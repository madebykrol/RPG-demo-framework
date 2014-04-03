#pragma once

#include "TopDownExample.h"
#include "IGameCharacter.generated.h"

UINTERFACE(MinimalAPI)
class UGameCharacter :public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IGameCharacter
{
	GENERATED_IINTERFACE_BODY()

	virtual OnTakeDmg();
	virtual OnDealDmg();
	virtual GetHealth();

};
