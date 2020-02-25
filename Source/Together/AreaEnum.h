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
	Dorm_2F_W_Hall,
	Dorm_Generator,
	Dorm_Warehouse,
	Dorm_SRoom1,
	Dorm_Breakroom,
	Dorm_SRoom2,
	Dorm_Garden,
	D101,
	D102,
	D103,
	D104,
	D105,
	D106,
	D107,
	D108,
	D109,
	D110,
	D111,
	D112,
	D113,
	D201,
	D202,
	D203,
	D204,
	D205,
	D206,
	D207,
	D208,
	D209,
	D210,
	D211
};
UCLASS()
class TOGETHER_API UAreaEnum : public UUserDefinedEnum
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	EArea Area;
};
