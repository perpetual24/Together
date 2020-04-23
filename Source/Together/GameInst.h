// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "Area.h"
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
	AArea* PlayerArea;

	UPROPERTY(BlueprintReadWrite)
	AArea* EnemyArea;

	UPROPERTY(BlueprintReadWrite)
	TArray<AArea*> Areas;
};
