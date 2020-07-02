// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//UE4
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"

//TD
#include "TD/Components/TDNavMovement.h"
#include "TD/TDGameModeBase.h"
#include "TD/Misc/TEffect.h"
#include "TD/Misc/TAbility.h"
#include "TD_AIPawnBase.generated.h"


UCLASS()
class TD_API ATD_AIPawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATD_AIPawnBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDAi")
	int Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDAi")
	int MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDAi")
	int armorType;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "TDProjectile")
	UFloatingPawnMovement* movement;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "TDProjectile")
	UTDNavMovement* TDNavMovementComp;

	/*
		damageMultiplierArr Matrix
				Light	Medium	Heavy	Fort	Hero	Unarmored
		Normal	1.0f	1.5f	1.0f	...		...		...
		Pierce	...		...		...		...		...		...
		Siege	...		...		...		...		...		...
		Magic	...		...		...		...		...		...
		Chaos	...		...		...		...		...		...
		Spells	...		...		...		...		...		...
		Hero	...		...		...		...		...		...
	*/

	float damageMultiplierArr[7][6] =
	{
		{ 1.0f, 1.5f, 1.0f, 0.7f, 1.0f, 1.0f },
		{ 2.0f, 0.75f, 1.0f, 0.35f, 0.5f, 1.5f },
		{ 1.0f, 0.5f, 1.0f, 1.5f, 0.5f, 1.5f },
		{ 1.25f, 0.75f, 2.0f, 0.35f, 0.5f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 0.5f, 1.0f, 1.0f }
	};

	TArray<FString> currentEffects;
	UTEffect* latestEffect;
	TArray<UTEffect*> effects;

	UFUNCTION(BlueprintCallable, Category = "TDAi")
	void AddDamage(int damage);

	UFUNCTION(BlueprintCallable, Category = "TDAi")
	void AddAbilityEffects(UTAbility* ability);

	UFUNCTION(BlueprintCallable, Category = "TDAi")
	int GetArmorType();

	UFUNCTION(BlueprintCallable, Category = "ArmorType")
	float getDamageMultiplier(int _damageType, int _armorType);

	UFUNCTION(BlueprintCallable, Category = "TDAi")
	void effectTick();

	UFUNCTION(BlueprintCallable, Category = "TDAi")
	void effectTickInit(UTEffect* effect);

	UFUNCTION(BlueprintCallable, Category = "TDAi")
	void effectTickEnd();

	FTimerHandle timerHandler;
	TArray<FTimerHandle> timerHandlers;
	TArray<UWorld*> tickTimers;

	void UpdateLevelStats();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "TDAi")
	int GoldOnDeath;

private:
		
	int Resistence;

	ATDGameModeBase* TDGameMode;

};
