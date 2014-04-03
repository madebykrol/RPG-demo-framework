// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "TopDownExamplePlayerController.generated.h"

UCLASS()
class ATopDownExamplePlayerController : public APlayerController
{
	GENERATED_UCLASS_BODY()

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) OVERRIDE;
	virtual void SetupInputComponent() OVERRIDE;
	// End PlayerController interface

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnMouseClickPressed();
	void OnMouseClickReleased();

	/** Called for side to side input */
	void MoveRight(float Val);
	void MoveForward(float Val);
};


