// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "AreaEnum.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EArea : uint8
{
	Dorm_1F_Bridge_Hall,
	Dorm_1F_E_Hall,
	Dorm_1F_E_Stair,
	Dorm_1F_W_Hall,
	Dorm_1F_W_Stair,
	Dorm_2F_Bridge_Hall,
	Dorm_2F_E_Hall,
	Dorm_2F_W_Hall
};
UCLASS()
class TOGETHER_API UAreaEnum : public UUserDefinedEnum
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	EArea Area;
};
