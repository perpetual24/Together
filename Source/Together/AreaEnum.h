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
	D_1F_Bridge_Hall,
	D_1F_E_Hall,
	D_1F_E_Stair,
	D_1F_W_Hall,
	D_1F_W_Stair,
	D_2F_Bridge_Hall,
	D_2F_E_Hall,
	D_2F_W_Hall,
	D_G01,
	D_G02,
	D_G03,
	D_G04,
	D_G05,
	D_Basement_Stair,
	D_Basement,
	D_Garden,
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
