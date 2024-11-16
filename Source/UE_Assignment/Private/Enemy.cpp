// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	CurrentHeight = FMath::FRandRange(-500.f, 500.f);
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0.f, 60 * DeltaTime, 0.f));
	if (PlayerPawn)
	{
		SetActorLocation(FMath::VInterpTo(GetActorLocation(), PlayerPawn->GetActorLocation() + FVector(0.f, 700.f, CurrentHeight), DeltaTime, 1.f));
		ShootCooldown = ShootCooldown - DeltaTime;
		if (FVector::Distance(PlayerPawn->GetActorLocation(), GetActorLocation()) < ShootingRange)
		{
			if (ShootCooldown < 0.0f)
			{
				// Reset Cooldown
				ShootCooldown = 0.8f;
				Shoot();
			}
		}
	}
	
}