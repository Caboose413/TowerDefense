// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//UE
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

//TD
#include "TD/Misc/TAbility.h"
#include "TD/Misc/TEffect.h"
#include "TD/Base/TD_AIPawnBase.h"
#include "Components/SphereComponent.h"
#include "ProjectileBase.generated.h"

UCLASS()
class TD_API AProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "TDProjectile")
	USphereComponent* TriggerSphere;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "TDProjectile")
	UProjectileMovementComponent* MovementComp;

	UFUNCTION(BlueprintCallable, Category = "TD_Projectile")
	AActor* GetTarget();

	UFUNCTION(BlueprintCallable, Category = "TD_Projectile")
	bool TargetValid();

	UFUNCTION(BlueprintCallable, Category = "TD_Projectile")
	void AddTarget(AActor* NewTarget);

	UFUNCTION(BlueprintCallable, Category = "TD_Projectile")
	void AddAbilitiy(ATD_AIPawnBase* NewTarget);

	private:

	UPROPERTY()
	AActor* Target;


};
