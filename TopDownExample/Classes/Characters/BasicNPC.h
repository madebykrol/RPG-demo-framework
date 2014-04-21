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

	void OnMousePressed(AController* player, FVector pos, FKey key);
	
	void OnMouseReleased(AController* player, FVector pos, FKey key);
	
	void OnMouseReleased(AController* user, FVector pos, AActor * target, FKey key);
	
	void OnMouseFocusedReleased(AController* player, FVector pos, FKey key);
	
	void OnMouseHoverIn(AController* player, FVector pos);
	
	void OnMouseHoverOut(AController* player, FVector pos);

	// Getters for maximum state
	int GetMaxHealth();
	int GetMaxMana();
	int GetMaxEnergy();

	// Getters for Current State
	int GetCurrentHealth();
	int GetCurrentMana();
	int GetCurrentEnergy();

	// Addition of status
	void AddHealth(int value);
	void AddEnergy(int value);
	void AddMana(int value);


	// Subtraction of status
	void SubtractHealth(int value);
	void SubtractEnergy(int value);
	void SubtractMana(int value);

	// Events
	void OnTakeDmg();
	void OnDealDmg();
	void OnDeath();
	void OnResurrect();
	
	void ReceiveActorBeginOverlap(AActor* Other);
};
