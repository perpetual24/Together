// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "HitType.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EHitType : uint8
{
	PlayerToEnm_General,
	PlayerToEnm_AP,
	PlayerToEnm_LocF,
	EnmToPlayer_High,
	EnmToPlayer_Low
};

UCLASS()
class TOGETHER_API UHitType : public UUserDefinedEnum
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	EHitType HitType;
};
