// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" 
#include "Components/ActorComponent.h"
#include "TEffect.generated.h"


UCLASS( BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TD_API UTEffect : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTEffect();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageTypeConfig")
	FString effectName;

	UPROPERTY()
	int effectIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageTypeConfig")
	bool hasDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageTypeConfig")
	int duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageTypeConfig")
	bool infinite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageTypeConfig")
	int manipulateHitpoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageTypeConfig")
	float manipulateWalkspeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageTypeConfig")
	int manipulateArmor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageTypeConfig")
	float manipulateDamageByMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageTypeConfig")
	int manipulateDamgeByInt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageTypeConfig")
	bool isTicking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageTypeConfig")
	float tickInterval; // 1.0f = 1sek || 0.5f = 0,5sek

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageTypeConfig")
	int tickCount; // how much ticks before effect ends

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageTypeConfig")
	float firstTickDelay;

	UFUNCTION(BlueprintCallable, Category = "TDAi")
	FString getEffectName();
};
