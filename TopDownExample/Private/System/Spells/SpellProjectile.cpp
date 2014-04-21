#include "TopDownExample.h"

ASpellProjectile::ASpellProjectile(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{
	CollisionComp = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->AlwaysLoadOnClient = true;
	CollisionComp->AlwaysLoadOnServer = true;
	CollisionComp->bTraceComplexOnMove = true;
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComp->SetCollisionObjectType(COLLISION_PROJECTILE);
	CollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComp->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	CollisionComp->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	CollisionComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	RootComponent = CollisionComp;

	MovementComp = PCIP.CreateDefaultSubobject<UProjectileMovementComponent>(this, TEXT("ProjectileComp"));
	MovementComp->UpdatedComponent = CollisionComp;
	MovementComp->InitialSpeed = 2000.0f;
	MovementComp->MaxSpeed = 2000.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->ProjectileGravityScale = 0.f;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;
}

void ASpellProjectile::SetSpell(USpell * spell)
{
	CurrentSpell = spell;
}

void ASpellProjectile::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	MovementComp->OnProjectileStop.AddDynamic(this, &ASpellProjectile::OnImpact);
	CollisionComp->MoveIgnoreActors.Add(Instigator);
	MyController = GetInstigatorController();
}

void ASpellProjectile::OnImpact(FHitResult const & HitResult)
{


	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Projectile Hit."));


	Explode();

	DisableAndDestroy();

}

void ASpellProjectile::Explode()
{
	// Do explosion damage to actors in the vincinity of impact.
}

void ASpellProjectile::DisableAndDestroy()
{

	// Destroy the actor within 2.0f 
	SetLifeSpan(CurrentSpell->GetProjectileDecay());
}