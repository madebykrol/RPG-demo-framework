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

	virtual void OnMousePressed(AController* user);
	virtual void OnMouseReleased(AController* user);
	virtual void OnMouseHoverIn(AController* user);
	virtual void OnMouseHoverOut(AController* user);
};