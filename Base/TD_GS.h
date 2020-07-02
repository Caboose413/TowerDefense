// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TD_GS.generated.h"

/**
 * 
 */
UCLASS()
class TD_API ATD_GS : public AGameStateBase
{
	GENERATED_BODY()
	

public:

	ATD_GS();

	UFUNCTION(BlueprintCallable, Category = "TD_GameState")
	void SetLive(int Amount);

	UFUNCTION(BlueprintCallable, Category = "TD_GameState")
	int GetLive();

	UFUNCTION(BlueprintCallable, Category = "TD_GameState")
	void AddLive(int Amount);

	UFUNCTION(BlueprintCallable, Category = "TD_GameState")
	void RemoveLive(int Amount);

private:

	int Currentlives;

};
