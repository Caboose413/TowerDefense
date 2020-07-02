// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TDGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TD_API ATDGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	


public:
	ATDGameModeBase();


	UFUNCTION(BlueprintCallable, Category = "TDGM")
		int SetLevel(int newLevel);

	UFUNCTION(BlueprintCallable, Category = "TDGM")
		int GetLevel();

	UFUNCTION(BlueprintCallable, Category = "TDGM")
		int addLevel(int toAdd);


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerConfig")
	int Difficulty;

private:

int Level;

};
