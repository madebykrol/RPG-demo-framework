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

	void ABasicNPC::OnTakeDmg(); 

	void ABasicNPC::OnMouseReleased(AController* user);
	
};
