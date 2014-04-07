#pragma once
#include "TopDownExample.h"
#include "MouseInteractionHandler.generated.h"

UCLASS()
class UMouseInteractionHandler : public UObject
{
	GENERATED_UCLASS_BODY()

protected:
	class IMouseInteractable * CurrentHoverTarget;
	class IMouseInteractable * CurrentPressTarget;
public:
	void Initialize();
	bool IsInteractable(AActor * actor);
	IMouseInteractable * GetInteractableObject(AActor * actor);
	
	bool TriggerMouseRelease(AController* player, FVector pos, bool focues);
	bool TriggerMouseRelease(AController* player, FVector pos, bool focues, IMouseInteractable * target);
	bool TriggerMousePress(IMouseInteractable * actor, AController* player, FVector pos);

	bool TriggerHoverToggle(IMouseInteractable * actor, AController * player, FVector pos);
	bool HasHoverTarget();
	void ClearHoverTarget(AController * player, FVector pos);
	IMouseInteractable * GetCurrentPressTarget();
};