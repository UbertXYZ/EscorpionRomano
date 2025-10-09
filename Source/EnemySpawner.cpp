#include "EnemySpawner.h"
#include "ScorpionEnemy.h"
#include "Kismet/GameplayStatics.h"

AEnemySpawner::AEnemySpawner()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AEnemySpawner::BeginPlay()
{
    Super::BeginPlay();
    GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AEnemySpawner::SpawnEnemy, SpawnInterval, true);
}

void AEnemySpawner::SpawnEnemy()
{
    if (EnemyClass)
    {
        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        if (PlayerPawn)
        {
            FVector SpawnLocation = PlayerPawn->GetActorLocation() + FMath::VRand().GetSafeNormal() * 1000.0f;
            FRotator SpawnRotation = FRotator::ZeroRotator;
            GetWorld()->SpawnActor<AScorpionEnemy>(EnemyClass, SpawnLocation, SpawnRotation);
        }
    }
}