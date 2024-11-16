// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Kismet/GameplayStatics.h"

APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bShouldAscend)
	{
		AscendPlayer(DeltaTime);
	}
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayerPawn::AscendPlayer(float DeltaTime)
{
	AddActorLocalOffset(FVector(.0f, .0f, DeltaTime * 30));
	CheckGoalHeightReached();
}

void APlayerPawn::CheckGoalHeightReached()
{
	if (GetActorLocation().Z > 3000.0f)
	{
		SetActorTickEnabled(false);
		GameWon();
	}
}

void APlayerPawn::NavigatePlayer(const FVector2D PositionDelta,const float MoveSpeed)
{
	AddActorLocalOffset(FVector(.0f, PositionDelta.X* MoveSpeed * GetWorld()->GetDeltaSeconds(), PositionDelta.Y * MoveSpeed * GetWorld()->GetDeltaSeconds()));
	bShouldAscend = false;
	CheckGoalHeightReached();
}

