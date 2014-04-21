#pragma once
#include "TopDownExample.h"

UGameCharacter::UGameCharacter(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{
	// Default Constructor code.
}

void IGameCharacter::OnTakeDmg()
{

}

void IGameCharacter::OnDealDmg()
{

}

void IGameCharacter::OnDeath() 
{

}

void IGameCharacter::OnResurrect()
{

}

void IGameCharacter::AddEnergy(int value)
{

}


void IGameCharacter::AddHealth(int value)
{

}

void IGameCharacter::AddMana(int value)
{

}

void IGameCharacter::SubtractEnergy(int value)
{

}

void IGameCharacter::SubtractHealth(int value)
{

}

void IGameCharacter::SubtractMana(int value)
{

}

int IGameCharacter::GetCurrentEnergy()
{
	return 0;
}

int IGameCharacter::GetCurrentHealth()
{
	return 0;
}

int IGameCharacter::GetCurrentMana()
{
	return 0;
}

int IGameCharacter::GetMaxHealth()
{
	return 0;
}

int IGameCharacter::GetMaxEnergy()
{
	return 0;
}

int IGameCharacter::GetMaxMana()
{
	return 0;
}
