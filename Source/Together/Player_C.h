// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Player_C.generated.h"

/**
 * 
 */
UCLASS()
class TOGETHER_API APlayer_C : public APlayerController
{
	GENERATED_BODY()

public:
    void SetPitchLimitToDefault();
    void SetPitchLimitDuringGrab();
};
