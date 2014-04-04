// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "TopDownExampleCharacter.generated.h"

UCLASS(Blueprintable)
class ATopDownExampleCharacter : public ACharacter, public IGameCharacter, public IMouseInteractable
{
	GENERATED_UCLASS_BODY()

public:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TSubobjectPtr<UCameraComponent> TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TSubobjectPtr<class USpringArmComponent> CameraBoom;
	
	virtual void Tick(float DeltaTime) OVERRIDE;

protected:
	TArray<TWeakObjectPtr<class UPrimitiveComponent>> StillBlocking;

	virtual void PurgeHiddenObjects(TArray<TWeakObjectPtr<class UPrimitiveComponent>> newComponents);

};

