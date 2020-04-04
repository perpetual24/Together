// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "SoundZeroTask.generated.h"

UENUM(BlueprintType)
enum class ESoundZeroTask : uint8
{
	Patrol_General,
	Patrol_Reverse,
	Patrol_ToRoom,
	Patrol_MoveFloor,
	SwitchOff_Nearby,
	SwitchOff_Power
};

UCLASS()
class TOGETHER_API USoundZeroTask : public UUserDefinedEnum
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	ESoundZeroTask SoundZeroTask;
};
