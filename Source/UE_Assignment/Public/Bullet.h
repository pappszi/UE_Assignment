// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Components/ArrowComponent.h"
#include "Bullet.generated.h"

UENUM()
enum class EBulletColor : uint8
{
	Red		UMETA(DisplayName = "Red"),
	Green	UMETA(DisplayName = "Green")
};

/**
 * 
 */
UCLASS()
class UE_ASSIGNMENT_API ABullet : public AActor
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaTime) override;
	ABullet(const FObjectInitializer& ObjectInitializer);
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", meta = (ExposeOnSpawn = "true"))
	EBulletColor BulletColor{ EBulletColor::Red };
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = Default)
	class UArrowComponent* Arrow{nullptr};

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Default)
	class UStaticMeshComponent* Cylinder{ nullptr };
private:
	
};
