// ScorpionWeapon.h
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScorpionWeapon.generated.h"

UCLASS()
class YOURPROJECT_API AScorpionWeapon : public AActor
{
    GENERATED_BODY()

public:
    AScorpionWeapon();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    UStaticMeshComponent* BaseMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    USkeletalMeshComponent* ArmMesh;

    // Potencia de disparo
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
    float FirePower;

    UFUNCTION(BlueprintCallable)
    void LoadProjectile();

    UFUNCTION(BlueprintCallable)
    void Fire();
};
