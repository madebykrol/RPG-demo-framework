#pragma once
#include "GameCharacter.generated.h"

UINTERFACE(MinimalAPI)
class UGameCharacter :public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IGameCharacter
{
	GENERATED_IINTERFACE_BODY()

	// Getters for maximum state
	virtual int GetMaxHealth();
	virtual int GetMaxMana();
	virtual int GetMaxEnergy();

	// Getters for Current State
	virtual int GetCurrentHealth();
	virtual int GetCurrentMana();
	virtual int GetCurrentEnergy();

	// Addition of status
	virtual void AddHealth(int value);
	virtual void AddEnergy(int value);
	virtual void AddMana(int value);


	// Subtraction of status
	virtual void SubtractHealth(int value);
	virtual void SubtractEnergy(int value);
	virtual void SubtractMana(int value);

	// Events
	virtual void OnTakeDmg();
	virtual void OnDealDmg();
	virtual void OnDeath();
	virtual void OnResurrect();

	
	UFUNCTION(BlueprintImplementableEvent)
	void OnActorBeginOverlapEvent(AActor * Other);
};
