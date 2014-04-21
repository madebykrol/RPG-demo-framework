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

	UPROPERTY()
	UInventory * Inventory;

	
	virtual void Tick(float DeltaTime) OVERRIDE;

	// Actions
	void CastSpell(USpell * spell);
	//void SwingWeapon(UWeapon * weapon);
	//void ShootWeapon(UWeapon * weapon);

protected:
	TArray<TWeakObjectPtr<class UPrimitiveComponent>> StillBlocking;

	virtual void PurgeHiddenObjects(TArray<TWeakObjectPtr<class UPrimitiveComponent>> newComponents);

	virtual void OnMousePressed(AController* user, FVector pos, FKey key);

	virtual void OnMouseReleased(AController* user, FVector pos, FKey key);

	virtual void OnMouseReleased(AController* user, FVector pos, AActor * target, FKey key);

	virtual void OnMouseFocusedReleased(AController* user, FVector pos, FKey key);

	virtual void OnMouseHoverIn(AController* user, FVector pos);

	virtual void OnMouseHoverOut(AController* user, FVector pos);

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
};

