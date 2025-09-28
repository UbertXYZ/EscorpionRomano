// ScorpionPawn.cpp
#include "ScorpionPawn.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

AScorpionPawn::AScorpionPawn()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AScorpionPawn::BeginPlay()
{
    Super::BeginPlay();
}

void AScorpionPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AScorpionPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAction("Load", IE_Pressed, this, &AScorpionPawn::Load);
    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AScorpionPawn::Fire);
}

void AScorpionPawn::Load()
{
    if (ControlledWeapon)
        ControlledWeapon->LoadProjectile();
}

void AScorpionPawn::Fire()
{
    if (ControlledWeapon)
        ControlledWeapon->Fire();
}
