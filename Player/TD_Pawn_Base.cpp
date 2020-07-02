// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_Pawn_Base.h"

// Sets default values
ATD_Pawn_Base::ATD_Pawn_Base()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATD_Pawn_Base::BeginPlay()
{
	Super::BeginPlay();
	SetActorRelativeRotation(FRotator(0.f, 0.f, 0.f));
}

// Called every frame
void ATD_Pawn_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATD_Pawn_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveX", this, &ATD_Pawn_Base::MoveForward);
	PlayerInputComponent->BindAxis("MoveY", this, &ATD_Pawn_Base::MoveSideward);


}


void ATD_Pawn_Base::AddMove(FVector Direction)
{
	AddActorLocalOffset(Direction * MoveSpeed * GetWorld()->GetDeltaSeconds());
}

void ATD_Pawn_Base::DestroySelf()
{
	UEmptyTest* TestU;
	TestU = NewObject<UEmptyTest>();
	TestU->DestroyOwner(this);
	
}

void ATD_Pawn_Base::MoveForward(float Value)
{
	if (abs(Value) > 0.f)
	{
		AddMove(FVector(Value, 0.f, 0.f));
	}
	
}

void ATD_Pawn_Base::MoveSideward(float Value)
{
	if (abs(Value) > 0.f)
	{
		AddMove(FVector(0.f, Value, 0.f));
	}
}