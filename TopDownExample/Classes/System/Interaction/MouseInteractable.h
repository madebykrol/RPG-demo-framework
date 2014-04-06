#pragma once
#include "TopDownExample.h"
#include "MouseInteractable.generated.h"

UINTERFACE(MinimalAPI)
class UMouseInteractable :public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IMouseInteractable
{
	GENERATED_IINTERFACE_BODY()

	virtual void OnMousePressed(AController* player);
	virtual void OnMouseReleased(AController* player);
	virtual void OnMouseHoverIn(AController* player);
	virtual void OnMouseHoverOut(AController* player);
};