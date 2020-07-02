// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_GS.h"

ATD_GS::ATD_GS()
{
	Currentlives = 100;
}


void ATD_GS::SetLive(int Amount)
{
	Currentlives = Amount;
}

int ATD_GS::GetLive()
{
	return Currentlives;
}

void ATD_GS::AddLive(int Amount)
{
	SetLive(GetLive() + Amount);
}

void ATD_GS::RemoveLive(int Amount)
{
	SetLive(GetLive() - Amount);
}
