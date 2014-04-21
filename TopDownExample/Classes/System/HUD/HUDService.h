#pragma once

#include "HUDService.generated.h"

UCLASS(MinimalAPI)
class UHUDService : public UObject
{
	GENERATED_UCLASS_BODY()

	AHUD * HUDReference;
public :
	void ShowConversationDialog(class UConversation * dialog);
	void ShowCharacterCheet(IGameCharacter * target);
	void ShowInventory(class UInventory * inventory);
	void ShowPlayerInventory(class UPlayerInventory * inventory);
	void ShowTargetDialog(IGameCharacter * target);
	void UpdateMiniMap();

	void SetHudReference(class AHUD * HUDRef);
};