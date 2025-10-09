// ScorpionProjectile.cpp
#include "ScorpionProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ScorpionEnemy.h"
#include "Kismet/GameplayStatics.h"

AScorpionProjectile::AScorpionProjectile()
{
    PrimaryActorTick.bCanEverTick = false;

    ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
    RootComponent = ProjectileMesh;

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->InitialSpeed = 3000.f;
    ProjectileMovement->MaxSpeed = 3000.f;
    ProjectileMovement->bRotationFollowsVelocity = true;
    ProjectileMovement->ProjectileGravityScale = 1.f; // gravedad realista

    // Enlazar el evento de colisión
    ProjectileMesh->OnComponentHit.AddDynamic(this, &AScorpionProjectile::OnHit);
}

void AScorpionProjectile::BeginPlay()
{
    Super::BeginPlay();
}

// Esta función se llama cuando el proyectil impacta con algo
void AScorpionProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor && OtherActor != this)
    {
        // Si el actor impactado es un enemigo, le hacemos daño
        if (AScorpionEnemy* Enemy = Cast<AScorpionEnemy>(OtherActor))
        {
            Enemy->ReceiveDamage(50.0f); // Daño configurable
        }

        // Destruir el proyectil después del impacto
        Destroy();
    }
}