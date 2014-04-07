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

	virtual void OnMousePressed(AController* player, FVector pos);
	virtual void OnMouseReleased(AController* player, FVector pos);
	virtual void OnMouseFocusedReleased(AController* player, FVector pos);
	virtual void OnMouseHoverIn(AController* player, FVector pos);
	virtual void OnMouseHoverOut(AController* player, FVector pos);
};