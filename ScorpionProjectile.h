// ScorpionProjectile.h
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScorpionProjectile.generated.h"

UCLASS()
class YOURPROJECT_API AScorpionProjectile : public AActor
{
    GENERATED_BODY()

public:
    AScorpionProjectile();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* ProjectileMesh;

    UPROPERTY(VisibleAnywhere)
    class UProjectileMovementComponent* ProjectileMovement;
};
