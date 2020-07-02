// Copyright Epic Games, Inc. All Rights Reserved.


#include "TDGameModeBase.h"

ATDGameModeBase::ATDGameModeBase()
{
	Difficulty = 2;
}

int ATDGameModeBase::SetLevel(int newLevel)
{
	return Level = newLevel;
}

int ATDGameModeBase::GetLevel()
{
	return Level;
}

int ATDGameModeBase::addLevel(int toAdd)
{
	return SetLevel(GetLevel() + toAdd);
}