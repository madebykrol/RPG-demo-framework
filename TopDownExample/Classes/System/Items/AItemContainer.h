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

	virtual void OnMousePressed(AController* user);

	virtual void OnMouseReleased(AController* user);

	virtual void OnMouseHoverIn(AController* user);

	virtual void OnMouseHoverOut(AController* user);


};
