#pragma once

#include "TopDownExample.h"
#include "GameCharacter.generated.h"

UINTERFACE(MinimalAPI)
class UGameCharacter :public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IGameCharacter
{
	GENERATED_IINTERFACE_BODY()

	virtual void OnTakeDmg();
	virtual void OnDealDmg();
	virtual void GetHealth();

};
