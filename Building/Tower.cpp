// Fill out your copyright notice in the Description page of Project Settings.

#include "Tower.h"


//
#include "UObject/UObjectBase.h"

// Sets default values
ATower::ATower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

 	AttackSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	RootComponent = AttackSphere;
	AttackSphere->InitSphereRadius(500.f);
}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();
	TowerOwner = GetOwner();
}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	attackTarget();
}

void ATower::attackTarget()
{
	if (Target == nullptr)
	{
		return;
	}


	ATD_AIPawnBase* TheTarget = Cast<ATD_AIPawnBase>(Target);

	if (TheTarget == nullptr)
	{
		return;
	}
	if (TheTarget->IsPendingKillPending())
	{
		TheTarget = nullptr;
		return;
	}
	FVector TargetLoc;
	if (TheTarget != nullptr)
	{
		TargetLoc = TheTarget->GetActorLocation();
	}
	if (FVector::Dist(TargetLoc, GetActorLocation()) > AttackSphere->GetScaledSphereRadius())
	{
		Target = nullptr;
		return;
	}

	FVector Location = GetTransform().GetLocation();
	FRotator Rotation = (TargetLoc - Location).GetSafeNormal().Rotation();
	FVector MyScale = GetTransform().GetScale3D();

	if (Projectile != nullptr)
	{
		AProjectileBase* SpawnedPro = GetWorld()->SpawnActor<AProjectileBase>(Projectile, FTransform(Rotation, Location, MyScale));

		if (SpawnedPro != nullptr)
		{
			SpawnedPro->SetOwner(this);
			SpawnedPro->AddTarget(TheTarget);
		}
		
	}
	
	//UE_LOG(LogTemp, Error, TEXT("Spawning"));

}

void ATower::SetTarget(AActor* NewTarget)
{
	if (NewTarget != nullptr)
	{
		Target = NewTarget;
	}
}

AActor* ATower::GetMyTarget()
{
	AActor* theTarget = Target;

	if (theTarget != nullptr)
	{
		return theTarget;
	}
	return nullptr;
}

bool ATower::IsTargetValid()
{
	if (Target == nullptr)
	{
		return false;
	}
	if (Target->IsPendingKillPending())
	{
		return false;
	}
	if (Target->IsPendingKill())
	{
		return false;
	}

	return true;
}

int ATower::getDamageType() 
{
	return damageType;
}