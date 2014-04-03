// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "TopDownExample.h"
#include "TopDownExampleCharacter.h"

ATopDownExampleCharacter::ATopDownExampleCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// Set size for player capsule
	CapsuleComponent->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	CharacterMovement->bOrientRotationToMovement = true; // Rotate character to moving direction
	CharacterMovement->RotationRate = FRotator(0.f, 640.f, 0.f);
	CharacterMovement->bConstrainToPlane = true;
	CharacterMovement->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = PCIP.CreateDefaultSubobject<USpringArmComponent>(this, TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("TopDownCamera"));
	TopDownCameraComponent->AttachTo(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUseControllerViewRotation = false; // Camera does not rotate relative to arm

	PrimaryActorTick.bCanEverTick = true;

}



void ATopDownExampleCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector  MyLocation = GetActorLocation();
	
	TArray<FHitResult> HitResults = TArray<FHitResult>();
	FVector StartLocation = TopDownCameraComponent->ComponentToWorld.GetLocation();

	TArray<TWeakObjectPtr<class UPrimitiveComponent>> blockingComponents;


	UWorld* WorldReference = GetWorld();

	FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	TraceParams.bTraceComplex = true;
	TraceParams.AddIgnoredActor(this);

	if (WorldReference->LineTraceMulti(HitResults, StartLocation, MyLocation, TraceParams, NULL)) {

		for (auto It = HitResults.CreateIterator(); It; ++It)
		{
			TWeakObjectPtr<class UPrimitiveComponent>  component = It->Component;

			blockingComponents.Add(component);
		}
	}

	PurgeHiddenObjects(blockingComponents);
}

void ATopDownExampleCharacter::PurgeHiddenObjects(TArray<TWeakObjectPtr<class UPrimitiveComponent>> newComponents) {
	for (auto It = StillBlocking.CreateIterator(); It; It++) {
		TWeakObjectPtr<class UPrimitiveComponent> component = *It;
		if (!newComponents.Contains(component)) {

			// Something like this is what I would love to do... However, Not quite there yet.
			/*
			UMaterialInstanceDynamic* MILight = UMaterialInstanceDynamic::Create(component->GetMaterial(0), this);

			MILight->SetScalarParameterValue(TEXT("Opacity"), 1);
			component->SetMaterial(0, MILight);
			*/

			component->SetVisibility(true);

			StillBlocking.Remove(component);
		}
	}

	for (auto It = newComponents.CreateIterator(); It; It++) {
		TWeakObjectPtr<class UPrimitiveComponent> component = *It;
		if (!StillBlocking.Contains(component)) {

			// Something like this is what I would love to do.. However, Not quite there yet
			/*
			UMaterialInstanceDynamic* MILight = UMaterialInstanceDynamic::Create(component->GetMaterial(0), this);

			MILight->SetScalarParameterValue(TEXT("Opacity"), 0.5);
			component->SetMaterial(0, MILight);
			*/

			component->SetVisibility(false);
			StillBlocking.Add(component);
		}
	}
}