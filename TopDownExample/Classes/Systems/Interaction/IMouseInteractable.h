#pragma once
#include "IMouseInteractable.h"
#include "IMouseInteractable.generated.h"

UINTERFACE(MinimalAPI)
class UMouseInteracable :public UInterface
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