// ScorpionPawn.h
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ScorpionWeapon.h"
#include "ScorpionPawn.generated.h"

UCLASS()
class YOURPROJECT_API AScorpionPawn : public APawn
{
    GENERATED_BODY()

public:
    AScorpionPawn();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
    AScorpionWeapon* ControlledWeapon;

    void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

    void Load();
    void Fire();
};
