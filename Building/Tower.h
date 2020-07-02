// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//UE4
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/DamageType.h"
#include "Components/SphereComponent.h"
#include "Components/ActorComponent.h"

//TD
#include "TD/Base/ProjectileBase.h"
#include "TD/Misc/TAbility.h"
#include "Tower.generated.h"

UCLASS()
class TD_API ATower : public AActor
{
	GENERATED_BODY()

private:
	
	
public:	

	// Sets default values for this actor's properties
	ATower();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerConfig")
	int damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerConfig")
	int damageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerConfig")
	float atkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerConfig")
	int aoe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerConfig")
	int range;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerConfig")
	int price;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerConfig")
	bool canAtkAir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerConfig")
	bool canAtkGround;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerConfig")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerConfig")
	FString	description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerConfig")
	bool hasInvetory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerConfig")
	int	inventorySlots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerConfig")
	TArray<TSubclassOf<ATower>> upgrades;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "TDProjectile")
	float test;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "TowerConfig")
	USphereComponent* AttackSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerConfig")
	TArray<TSubclassOf<UTAbility>> Abilities;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerConfig")
	TSubclassOf<AProjectileBase> Projectile;


	UFUNCTION()
	void attackTarget();

	//UFUNCTION()
	//void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//UFUNCTION()
	//void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable, Category = "TowerConfig")
	void SetTarget(AActor* NewTarget);

	UFUNCTION(BlueprintCallable, Category = "TowerConfig")
	AActor* GetMyTarget();

	UFUNCTION(BlueprintCallable, Category = "TowerConfig")
	bool IsTargetValid();

	UFUNCTION(BlueprintCallable, Category = "TowerConfig")
	int getDamageType();

private:
	
	UPROPERTY()
	AActor* Target;

	UPROPERTY()
	AActor* TowerOwner;



};
