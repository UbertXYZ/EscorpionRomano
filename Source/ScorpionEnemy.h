#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ScorpionEnemy.generated.h"

UCLASS()
class ESCORPIONROMANO_API AScorpionEnemy : public ACharacter
{
    GENERATED_BODY()

public:
    AScorpionEnemy();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enemy")
    float Health = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enemy")
    float Damage = 10.0f;

    // Lógica para recibir daño
    UFUNCTION()
    void ReceiveDamage(float Amount);

    // Lógica para atacar al jugador
    void AttackPlayer();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
};