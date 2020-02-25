// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "AreaEnum.h"
#include "Engine/GameInstance.h"
#include "GameInst.generated.h"

/**
 * 
 */
UCLASS()
class TOGETHER_API UGameInst : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TArray<UPhysicalMaterial*> Surface;

	UPROPERTY(BlueprintReadWrite)
	EArea PlayerArea;

	UPROPERTY(BlueprintReadWrite)
	EArea EnermyArea;
};
