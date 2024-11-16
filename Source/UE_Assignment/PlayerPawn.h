// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class UE_ASSIGNMENT_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	APlayerPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadOnly)
	int32 Health{ 6 };

	UPROPERTY(BlueprintReadWrite)
	bool bShouldAscend{ true };

	UFUNCTION(BlueprintImplementableEvent)
	void GameWon();

private:
	UFUNCTION(BlueprintCallable)
	void SetHealth(const int32 newHealth) { Health = newHealth; };
	
	void AscendPlayer(float DeltaTime);

	void CheckGoalHeightReached();

	UFUNCTION(BlueprintCallable)
	void NavigatePlayer(const FVector2D PositionDelta,const float MoveSpeed = 120.f);
};
