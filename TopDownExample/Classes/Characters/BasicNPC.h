// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Character.h"
#include "BasicNPC.generated.h"

/**
 * 
 */
UCLASS()
class ABasicNPC : public ACharacter, public  IGameCharacter, public IMouseInteractable
{
	GENERATED_UCLASS_BODY()

	void OnTakeDmg(); 

	void OnMousePressed(AController* player);

	void OnMouseReleased(AController* player);

	void OnMouseHoverIn(AController* player);

	void OnMouseHoverOut(AController* player);
	
};
