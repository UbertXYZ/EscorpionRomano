// ScorpionWeapon.cpp
#include "ScorpionWeapon.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "GameFramework/ProjectileMovementComponent.h"

AScorpionWeapon::AScorpionWeapon()
{
    PrimaryActorTick.bCanEverTick = true;

    BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
    RootComponent = BaseMesh;

    ArmMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ArmMesh"));
    ArmMesh->SetupAttachment(RootComponent);

    FirePower = 3000.f; // potencia por defecto
}

void AScorpionWeapon::BeginPlay()
{
    Super::BeginPlay();
}

void AScorpionWeapon::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AScorpionWeapon::LoadProjectile()
{
    // Animación de cargar proyectil (puedes disparar evento blueprint aquí)
}

void AScorpionWeapon::Fire()
{
    // Aquí deberías spawn un proyectil físico
    UE_LOG(LogTemp, Log, TEXT("¡Escorpión disparado! Potencia %f"), FirePower);
}
