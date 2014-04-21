#pragma once

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
	
	void TriggerMouseRelease(AController* player, FVector pos, bool focues, FKey key);
	void TriggerMouseRelease(AController* player, FVector pos, AActor * target, FKey key);
	void TriggerMousePress(IMouseInteractable * actor, AController* player, FVector pos, FKey key);

	void TriggerHoverToggle(IMouseInteractable * actor, AController * player, FVector pos);
	bool HasHoverTarget();
	void ClearHoverTarget(AController * player, FVector pos);
	IMouseInteractable * GetCurrentPressTarget();
};