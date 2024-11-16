// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

ABullet::ABullet(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	Arrow = ObjectInitializer.CreateDefaultSubobject<UArrowComponent>(this, TEXT("Arrow"));
	RootComponent = Arrow;
	Cylinder = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Cylinder"));
	Arrow->SetupAttachment(GetRootComponent());
	Cylinder->SetupAttachment(Arrow);
}

void ABullet::BeginPlay()
{
	Super::BeginPlay();
}

void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorWorldOffset(Arrow->GetForwardVector() * (BulletColor == EBulletColor::Green ? 2000.f : 2500.f)*DeltaTime);

}
