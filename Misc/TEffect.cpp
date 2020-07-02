// Fill out your copyright notice in the Description page of Project Settings.
#include "TEffect.h"

// Sets default values for this component's properties
UTEffect::UTEffect()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickInterval = 1.0f;
	// ...
}

// Called when the game starts
void UTEffect::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UTEffect::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FString UTEffect::getEffectName()
{
	return effectName;
}
