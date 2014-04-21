#include "TopDownExample.h"

UHUDService::UHUDService(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{

}

void UHUDService::UpdateMiniMap()
{
	
}

void UHUDService::ShowCharacterCheet(IGameCharacter * target)
{
	AMyHUD * cHudRef = Cast<AMyHUD>(HUDReference);
}

void UHUDService::ShowTargetDialog(IGameCharacter * target) {

}

void UHUDService::ShowConversationDialog(class UConversation * dialog)
{
	
}

void UHUDService::ShowPlayerInventory(class UPlayerInventory * inventory)
{

}

void UHUDService::ShowInventory(class UInventory * inventory)
{
	AMyHUD * cHudRef = Cast<AMyHUD>(HUDReference);
	cHudRef->DrawWidget();
}

void UHUDService::SetHudReference(class AHUD * HUDRef)
{
	HUDReference = HUDRef;
}