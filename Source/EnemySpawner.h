#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class ESCORPIONROMANO_API AEnemySpawner : public AActor
{
    GENERATED_BODY()

public:
    AEnemySpawner();

    UPROPERTY(EditAnywhere, Category="Spawning")
    TSubclassOf<class AScorpionEnemy> EnemyClass;

    UPROPERTY(EditAnywhere, Category="Spawning")
    float SpawnInterval = 5.0f;

protected:
    virtual void BeginPlay() override;

    void SpawnEnemy();

    FTimerHandle SpawnTimerHandle;
};