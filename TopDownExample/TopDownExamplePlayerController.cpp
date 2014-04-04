// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "TopDownExample.h"
#include "TopDownExamplePlayerController.h"
#include "EngineUserInterfaceClasses.h"

ATopDownExamplePlayerController::ATopDownExamplePlayerController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::CardinalCross;


}

void ATopDownExamplePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// Look for hoover

	const ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	FHitResult Hit;
	FVector2D ScreenPoint = LocalPlayer->ViewportClient->GetMousePosition();
	if (GetHitResultAtScreenPosition(ScreenPoint, COLLISION_WEAPON, true, Hit))
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Moused over"));
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

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ATopDownExamplePlayerController::OnMouseClickPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &ATopDownExamplePlayerController::OnMouseClickReleased);

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

void ATopDownExamplePlayerController::OnMouseClickPressed()
{
	// set flag to keep updating destination until released
	


	// Select world object.


	

	bMoveToMouseCursor = true;
}

void ATopDownExamplePlayerController::OnMouseClickReleased()
{
	// clear flag to indicate we should stop updating the destination

	APawn* const Pawn = GetPawn();

	FHitResult ClickHit;
	GetHitResultUnderCursor(ECC_Visibility, false, ClickHit);


	if (Pawn)
	{
		float distance = FVector::Dist(ClickHit.ImpactPoint, Pawn->GetActorLocation());

		if (distance < 200) {

			IMouseInteractable * object = InterfaceCast<IMouseInteractable>(ClickHit.GetActor());

			if (object) {

				object->OnMouseReleased(this);
			}
		}

	}

	bMoveToMouseCursor = false;
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