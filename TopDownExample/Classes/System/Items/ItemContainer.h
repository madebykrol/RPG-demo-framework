#pragma once
#include "TopDownExample.h"
#include "ItemContainer.generated.h"

UINTERFACE(MinimalAPI)
class UItemContainer :public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IItemContainer
{
	GENERATED_IINTERFACE_BODY()

	virtual void OnOpen(AController* user);
};

