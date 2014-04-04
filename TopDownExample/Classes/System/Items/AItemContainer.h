// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "GameFramework/Actor.h"
#include "ItemContainer.h"
#include "AItemContainer.generated.h"


/**
 * 
 */
UCLASS()
class AAItemContainer : public AActor, public IItemContainer
{
	GENERATED_UCLASS_BODY()

	void AAItemContainer::OnOpen(AController* user);
	
};
