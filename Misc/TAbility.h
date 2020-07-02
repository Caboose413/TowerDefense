// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TEffect.h"
#include "TAbility.generated.h"


UCLASS( BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TD_API UTAbility : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTAbility();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	TArray<TSubclassOf<UTEffect>> effects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	int manaCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	int cooldown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	int aoe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	int damage;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	TArray<TSubclassOf<UTEffect>> getEffects();
};
