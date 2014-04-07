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

	void OnMousePressed(AController* player, FVector pos);

	void OnMouseReleased(AController* player, FVector pos);

	void OnMouseFocusedReleased(AController* user, FVector pos, IMouseInteractable * target);

	void OnMouseFocusedReleased(AController* player, FVector pos);

	void OnMouseHoverIn(AController* player, FVector pos);

	void OnMouseHoverOut(AController* player, FVector pos);
	
};
