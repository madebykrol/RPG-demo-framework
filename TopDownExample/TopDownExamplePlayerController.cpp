// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "TopDownExample.h"
#include "TopDownExamplePlayerController.h"
#include "EngineUserInterfaceClasses.h"

ATopDownExamplePlayerController::ATopDownExamplePlayerController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::CardinalCross;
	MouseInteractionHandler = NewObject<UMouseInteractionHandler>(this);

	HUDService = NewObject<UHUDService>(this);
	HUDService->SetHudReference(this->GetHUD());
	HUDService->ShowPlayerInventory(NewObject<UPlayerInventory>(this));
	
	// GMode = Cast<ATopDownExampleGameMode>(GetWorld()->GameState->GetDefaultGameMode());

	static ConstructorHelpers::FObjectFinder<UClass> SpellBPClass(TEXT("Class'/Game/Blueprints/SpellProjectile.SpellProjectile_C'"));
	if (SpellBPClass.Object != NULL) {
		SpellprojectileClass = SpellBPClass.Object;
	}
}

void ATopDownExamplePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// Look for hoover

	const ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	FHitResult Hit;
	FVector2D ScreenPoint = LocalPlayer->ViewportClient->GetMousePosition();
	GetHitResultAtScreenPosition(ScreenPoint, COLLISION_WEAPON, true, Hit);

	AActor * actor = Hit.GetActor();
	
	if (MouseInteractionHandler->IsInteractable(actor)) {
		IMouseInteractable * object = MouseInteractionHandler->GetInteractableObject(actor);
		MouseInteractionHandler->TriggerHoverToggle(object, this, Hit.ImpactPoint);

		HUDService->ShowInventory(NULL);
	}
	else {
		MouseInteractionHandler->ClearHoverTarget(this, Hit.ImpactPoint);
	}

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

void ATopDownExamplePlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("LeftClick", IE_Pressed, this, &ATopDownExamplePlayerController::MouseClickPressedLeft);
	InputComponent->BindAction("LeftClick", IE_Released, this, &ATopDownExamplePlayerController::MouseClickReleasedLeft);
	InputComponent->BindAction("RightClick", IE_Pressed, this, &ATopDownExamplePlayerController::MouseClickPressedRight);
	InputComponent->BindAction("RightClick", IE_Released, this, &ATopDownExamplePlayerController::MouseClickReleasedRight);
	InputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &ATopDownExamplePlayerController::MouseClickPressedLeftShift);
	
	// WASD movement of character
	InputComponent->BindAxis("MoveForward", this, &ATopDownExamplePlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATopDownExamplePlayerController::MoveRight);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ATopDownExamplePlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &ATopDownExamplePlayerController::MoveToTouchLocation);
}

void ATopDownExamplePlayerController::MoveToMouseCursor()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	

	if (Hit.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(Hit.ImpactPoint);
	}
}

void ATopDownExamplePlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void ATopDownExamplePlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const Pawn = GetPawn();
	if (Pawn)
	{
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();

		float const Distance = FVector::Dist(DestLocation, Pawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if (NavSys && (Distance > 120.0f))
		{
			NavSys->SimpleMoveToLocation(this, DestLocation);
		}


	}
}

// Untill custom delegations for UInputComponent BindAction works, this will suffice
void ATopDownExamplePlayerController::MouseClickPressedRight() {
	OnMouseClickPressed(EKeys::RightMouseButton);
}

void ATopDownExamplePlayerController::MouseClickPressedLeftShift() {
	OnMouseShiftClickPressed(EKeys::LeftMouseButton);
}

void ATopDownExamplePlayerController::MouseClickPressedLeft() {
	OnMouseClickPressed(EKeys::LeftMouseButton);
}

void ATopDownExamplePlayerController::MouseClickReleasedRight() {
	OnMouseClickReleased(EKeys::RightMouseButton);
}

void ATopDownExamplePlayerController::MouseClickReleasedLeft() {
	OnMouseClickReleased(EKeys::LeftMouseButton);
}

void ATopDownExamplePlayerController::OnMouseShiftClickPressed(FKey key)
{
	APawn* const Pawn = GetPawn();

	FHitResult ClickHit;
	GetHitResultUnderCursor(COLLISION_PROJECTILE, false, ClickHit);

	// first, rotate player to click location
	// Skip rotation on Z-axis.
	FVector playerLocation(Pawn->GetActorLocation().X, Pawn->GetActorLocation().Y, 0.0f);
	FVector hitPoint(ClickHit.ImpactPoint.X, ClickHit.ImpactPoint.Y, 0.0f);

	FRotator newRotation = (hitPoint - playerLocation).Rotation();

	Pawn->SetActorRotation(newRotation);

	// if pawn.
	if (Pawn) {

		// first, rotate player to click location

		FVector playerLocation = Pawn->GetActorLocation();
		FVector hitPoint = ClickHit.ImpactPoint;

		// second, check if we actually hit a "Actor"
		if (ClickHit.GetActor()) {


			// Then we check distance
			float distance = FVector::Dist(ClickHit.ImpactPoint, Pawn->GetActorLocation());
			if (key == EKeys::LeftMouseButton) {
				// Cast to TopDownExampleCharacter
				ATopDownExampleCharacter* Char = Cast<ATopDownExampleCharacter>(Pawn);

				// Select the spell we are casting.
				USpell* Spell = NewObject<USpell>(this);
				Spell->SetSpellProjectileClass(SpellprojectileClass);

				// Cast the spell.
				Char->CastSpell(Spell);
			}
		}
	}
}

void ATopDownExamplePlayerController::OnMouseClickPressed(FKey key)
{
	// set flag to keep updating destination until released
	APawn* const Pawn = GetPawn();

	bool clickedOnClickable = false;

	FHitResult ClickHit;
	GetHitResultUnderCursor(COLLISION_PROJECTILE, false, ClickHit);

	// if pawn.
	if (Pawn) {
		
		// second, check if we actually hit a "Actor"
		if (ClickHit.GetActor()) {

			
			// Then we check distance
			float distance = FVector::Dist(ClickHit.ImpactPoint, Pawn->GetActorLocation());

			// if distance is within reach.
			if (distance < 2000) {

				if (MouseInteractionHandler->IsInteractable(ClickHit.GetActor())) {
					IMouseInteractable * object = MouseInteractionHandler->GetInteractableObject(ClickHit.GetActor());

					MouseInteractionHandler->TriggerMousePress(object, this, ClickHit.ImpactPoint, key);
					clickedOnClickable = true;
				}
			}
		}

	}

	if (!clickedOnClickable) {
		bMoveToMouseCursor = true;
	}
	else {
		// first, rotate player to click location

		FVector playerLocation(Pawn->GetActorLocation().X, Pawn->GetActorLocation().Y, 0.0f);
		FVector hitPoint(ClickHit.ImpactPoint.X, ClickHit.ImpactPoint.Y, 0.0f);

		FRotator newRotation = (hitPoint - playerLocation).Rotation();

		Pawn->SetActorRotation(newRotation);
	}
}

void ATopDownExamplePlayerController::OnMouseClickReleased(FKey key)
{
	
	APawn* const Pawn = GetPawn();


	FHitResult ClickHit;
	GetHitResultUnderCursor(COLLISION_WEAPON, false, ClickHit);
	
	bool hasReleased = false;

	// if pawn.
	if (Pawn) {
		// first, check if we actually hit a "Actor"
		if (ClickHit.GetActor()) {

			if (MouseInteractionHandler->IsInteractable(ClickHit.GetActor())) {
				IMouseInteractable * object = MouseInteractionHandler->GetInteractableObject(ClickHit.GetActor());
				
				if (object != MouseInteractionHandler->GetCurrentPressTarget()) {
					// Released mouse starting from one interactable on another.
					MouseInteractionHandler->TriggerMouseRelease(this, ClickHit.ImpactPoint, ClickHit.GetActor(), key);
				}
				else {
					// Normal drag release operation.
					MouseInteractionHandler->TriggerMouseRelease(this, ClickHit.ImpactPoint, true, key);
				}

				hasReleased = true;
			}
		}

	}

	if (!hasReleased) {
		MouseInteractionHandler->TriggerMouseRelease(this, ClickHit.ImpactPoint, false, key);
	}
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}

void ATopDownExamplePlayerController::OnUsePrimaryAttack()
{
	// Use primary skill.

	// As character is default caster, use a casting spell.

	// Cast the "spell" from the players center, in the direction the player is facing.


}

void ATopDownExamplePlayerController::MoveRight(float Value)
{
	// add movement in that direction
	//AddMovementInput(FVector(0.f, -1.f, 0.f), Value);
}

void ATopDownExamplePlayerController::MoveForward(float Value)
{
	// add movement in that direction
	//AddMovementInput(FVector(-1.f, 0.f, 0.f), Value);
}