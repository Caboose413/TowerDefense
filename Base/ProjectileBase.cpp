// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileBase.h"

//
#include "TD/Building/Tower.h"


// Sets default values
AProjectileBase::AProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

AActor* AProjectileBase::GetTarget()
{
	AActor* MyOwner = GetOwner();

	if (MyOwner != nullptr)
	{
		return Cast<ATower>(MyOwner)->GetMyTarget();
	}
	return nullptr;
}

bool AProjectileBase::TargetValid()
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

void AProjectileBase::AddTarget(AActor* NewTarget)
{
	Target = NewTarget;
}

void AProjectileBase::AddAbilitiy(ATD_AIPawnBase* NewTarget)
{
	if (NewTarget == nullptr)
	{
		return;
	}

	ATD_AIPawnBase* TheTarget = Cast<ATD_AIPawnBase>(NewTarget);

	if (TheTarget == nullptr)
	{
		//Destroy();
		return;
	}
	ATower* OwnerTower = nullptr;

	if (!OwnerTower)
	{
		OwnerTower = Cast<ATower>(GetOwner());
		if (!OwnerTower)
		{
			Destroy();
			return;
		}
	}

	UTEffect* Effect = nullptr;

	if (OwnerTower)
	{
		for (auto &mAbility : OwnerTower->Abilities)
		{
			UTAbility* Ability = Cast<UTAbility>(mAbility.GetDefaultObject());

			if (!Ability)
			{
				//Destroy();
				continue;
			}

			int targetArmorType = TheTarget->armorType;
			int towerDamageType = OwnerTower->damageType;

			float damageMultiplier = TheTarget->getDamageMultiplier(towerDamageType, targetArmorType);

			int calculatedDamage = OwnerTower->damage * damageMultiplier;

			TheTarget->AddDamage(calculatedDamage);
			TheTarget->AddAbilityEffects(Ability);

			//Destroy();
		}
	}
	//Destroy();
}


