// Fill out your copyright notice in the Description page of Project Settings.


#include "EmptyTest.h"

UEmptyTest::UEmptyTest()
{
	
}

void UEmptyTest::DestroyOwner(APawn* OwnerPawn)
{
	OwnerPawn->Destroy(true);
}

