#include "ScorpionEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ScorpionPawn.h"

AScorpionEnemy::AScorpionEnemy()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AScorpionEnemy::BeginPlay()
{
    Super::BeginPlay();
}

void AScorpionEnemy::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Buscar al jugador y moverse hacia él
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerPawn)
    {
        FVector Direction = (PlayerPawn->GetActorLocation() - GetActorLocation()).GetSafeNormal();
        AddMovementInput(Direction, 1.0f);
    }
}

void AScorpionEnemy::ReceiveDamage(float Amount)
{
    Health -= Amount;
    if (Health <= 0)
    {
        Destroy();
    }
}

void AScorpionEnemy::AttackPlayer()
{
    // Obtener una referencia al jugador (primer jugador en el mundo)
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerPawn)
    {
        // Si el jugador existe, aplicarle daño usando el sistema de daño de Unreal
        // AttackDamage es la cantidad de daño, GetController() es el instigador, this es el causante
        UGameplayStatics::ApplyDamage(PlayerPawn, AttackDamage, GetController(), this, nullptr);
    }
}