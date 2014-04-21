// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "GameFramework/Actor.h"
#include "AItemContainer.generated.h"


/**
 * 
 */
UCLASS()
class AAItemContainer : public AActor, public IItemContainer, public IMouseInteractable
{
	GENERATED_UCLASS_BODY()

	void AAItemContainer::OnOpen(AController* user);

	virtual void OnMousePressed(AController* user, FVector pos, FKey key);

	virtual void OnMouseReleased(AController* user, FVector pos, FKey key);

	virtual void OnMouseReleased(AController* user, FVector pos, AActor * target, FKey key);

	virtual void OnMouseFocusedReleased(AController* user, FVector pos, FKey key);
	

	virtual void OnMouseHoverIn(AController* user, FVector pos);

	virtual void OnMouseHoverOut(AController* user, FVector pos);


};
