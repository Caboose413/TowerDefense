// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TD/EmptyTest.h"
#include "TD_Pawn_Base.generated.h"

UCLASS()
class TD_API ATD_Pawn_Base : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATD_Pawn_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlyingComp")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlyingComp")
	TArray<TSubclassOf<UActorComponent>> test;


public:
	

	UFUNCTION(BlueprintCallable, Category = "PlayerPawn")
	void AddMove(FVector Direction);

	UFUNCTION(BlueprintCallable, Category = "FlyingComp")
	void DestroySelf();

	void MoveForward(float Value);
	void MoveSideward(float Value);

};
