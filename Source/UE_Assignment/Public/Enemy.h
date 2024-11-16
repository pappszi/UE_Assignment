// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "../PlayerPawn.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class UE_ASSIGNMENT_API AEnemy : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	AEnemy();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	int32 Health{ 3 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", meta = (ExposeOnSpawn = "true"))
	APlayerPawn* PlayerPawn{ nullptr };

	UPROPERTY(BlueprintReadWrite)
	float CurrentHeight{ 0 };

	UPROPERTY(BlueprintReadWrite)
	float ShootingRange{ 1000 };

	UFUNCTION(BlueprintImplementableEvent)
	void Shoot();

private:
	UFUNCTION(BlueprintCallable)
	void Damage() { Health--; };
	
	float ShootCooldown{ 0 };
};
