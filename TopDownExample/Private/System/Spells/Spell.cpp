#include "TopDownExample.h"

USpell::USpell(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{
	bIsAOE = false;
	bExplodesOnImpact = true;
	BlastRadius = 150.0f;
	ProjectileDecay = 0.5f;
}

bool USpell::IsAOE()
{
	return bIsAOE;
}

bool USpell::ExplodesOnImpact()
{
	return bExplodesOnImpact;
}

float USpell::GetBlastRadius()
{
	return BlastRadius;
}

int USpell::GetBlastDamage(float distanceToImpactPoint)
{
	return 1.0f;
}

void USpell::SetSpellProjectileClass(TSubclassOf<class ASpellProjectile> projectileClass)
{
	SpellprojectileClass = projectileClass;
}

float USpell::GetProjectileDecay()
{
	return ProjectileDecay;
}

TSubclassOf<class ASpellProjectile> USpell::GetSpellProjectileClass()
{
	return SpellprojectileClass;
}

