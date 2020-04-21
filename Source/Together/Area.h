// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "AreaEnum.h"
#include "Area.generated.h"

/**
 * 
 */
UCLASS()
class TOGETHER_API AArea : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
	EArea AreaEnum;
};
