// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_C.h"

void APlayer_C::SetPitchLimitToDefault()
{
	PlayerCameraManager->ViewPitchMin = -80;
	PlayerCameraManager->ViewPitchMax = 70;
}

void APlayer_C::SetPitchLimitDuringGrab()
{
	PlayerCameraManager->ViewPitchMin = -80;
	PlayerCameraManager->ViewPitchMax = 10;
}
