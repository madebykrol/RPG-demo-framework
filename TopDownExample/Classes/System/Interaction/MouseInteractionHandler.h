#pragma once
#include "TopDownExample.h"
#include "MouseInteractionHandler.generated.h"

UCLASS()
class UMouseInteractionHandler : public UObject
{
	GENERATED_UCLASS_BODY()

protected:
	class IMouseInteractable * CurrentHoverTarget;
public:
	void Initialize();
	bool IsInteractable(AActor * actor);
	IMouseInteractable * GetInteractableObject(AActor * actor);
	bool TriggerHoverToggle(IMouseInteractable * actor, AController * player);
	bool HasHoverTarget();
	void ClearHoverTarget(AController * player);
};