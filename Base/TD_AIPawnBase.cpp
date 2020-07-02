// Fill out your copyright notice in the Description page of Project Settings.

#include "TD_AIPawnBase.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "UObject/ConstructorHelpers.h"
#include "TimerManager.h"

// Sets default values
ATD_AIPawnBase::ATD_AIPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComp"));
	//TDNavMovementComp = CreateDefaultSubobject<UTDNavMovement>(TEXT("TDMovementComp"));
	//movement->InitializeComponent();
}

// Called when the game starts or when spawned
void ATD_AIPawnBase::BeginPlay()
{
	Super::BeginPlay();
	
	AGameModeBase* GM = GetWorld()->GetAuthGameMode();

	if (GM)
	{
		TDGameMode = Cast<ATDGameModeBase>(GM);
	}
    
	UpdateLevelStats();
}

// Called every frame
void ATD_AIPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATD_AIPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATD_AIPawnBase::AddDamage(int damage)
{
	float RistDmg = damage + Resistence;
	float RistPerc = damage / RistDmg;
	float FinDmg = damage * RistPerc;

	Health -= FinDmg;

	//UE_LOG(LogTemp, Error, TEXT("Dmg %f"), FinDmg);
	//UE_LOG(LogTemp, Error, TEXT("Health %i"), Health);
	if (Health <= 0)
	{
		//UE_LOG(LogTemp, Error, TEXT("Destroy"));
		//effectTickEnd();
		Destroy();
	}
}

void ATD_AIPawnBase::AddAbilityEffects(UTAbility* ability)
{
	for (auto &mEffects : ability->effects)
	{
		//UE_LOG(LogTemp, Error, TEXT("in for(OwnerTower)"));
		//UTAbility* Ability = Cast<UTAbility>(mAbility.GetDefaultObject());
		UTEffect* effect = Cast<UTEffect>(mEffects.GetDefaultObject());
		currentEffects.Add(effect->effectName);

		if (effect != nullptr)
		{
			//UE_LOG(LogTemp, Error, TEXT("Check if effect is ticking"));
			//UE_LOG(LogTemp, Error, TEXT("test %s"), effect->isTicking ? TEXT("true") : TEXT("false"));

			if (effect->isTicking)
			{
				if(currentEffects.Find(effect->effectName)) 
				{
					//effectTickEnd(); // remove effect and reapply it
					effectTickInit(effect);
				}
				else
				{
					effectTickInit(effect);
				}
				UE_LOG(LogTemp, Error, TEXT("Call TickInit"));		
			}
			else
			{
				if (movement != nullptr)
				{
					//float newSpeed = movement->MaxSpeed += effect->manipulateWalkspeed;
					//movement->MaxSpeed = FMath::Clamp<float>(newSpeed, 500.f, 1300.f);
					movement->MaxSpeed = 500.f;
				}
			}
		}
	}
}

int ATD_AIPawnBase::GetArmorType()
{
	return armorType;
}

void ATD_AIPawnBase::UpdateLevelStats()
{
	if (!TDGameMode)
	{
		return;
	}

	int Level = TDGameMode->GetLevel(); 

	Resistence = (Level * 10);
	Health += (Level * TDGameMode->Difficulty);
}

float ATD_AIPawnBase::getDamageMultiplier(int _damageType, int _armorType)
{
	return damageMultiplierArr[_damageType][_armorType];
}

void ATD_AIPawnBase::effectTick()
{
	int counter = 0;
	if (counter < latestEffect->tickCount)
	{
		if (latestEffect->manipulateHitpoints != 0) {
			AddDamage(latestEffect->manipulateHitpoints);
		}
		
		return;
	}
	else
	{
		if (latestEffect->manipulateWalkspeed != 0) {
			movement->MaxSpeed = 1300.0f;
		}
		//effectTickEnd();
		return;
	}
	counter++;
}

void ATD_AIPawnBase::effectTickInit(UTEffect* effect)
{
	if (!effect->isTicking)
	{
		return;
	}

	latestEffect = effect;

	FTimerHandle _timerHandler;
	int newTimerIndex = timerHandlers.Add(_timerHandler);

	GetWorldTimerManager().SetTimer(timerHandlers[newTimerIndex], this, &ATD_AIPawnBase::effectTick, latestEffect->tickInterval, true, latestEffect->firstTickDelay);
}

void ATD_AIPawnBase::effectTickEnd()
{
	GetWorld()->GetTimerManager().ClearTimer(timerHandler);
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}


