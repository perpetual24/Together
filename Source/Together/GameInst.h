// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "Area.h"
#include "Kismet/GameplayStatics.h"
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

	UPROPERTY(BlueprintReadWrite, Category = "PawnArea")
	AArea* PlayerArea;

	UPROPERTY(BlueprintReadWrite, Category = "PawnArea")
	AArea* EnemyArea;

	UPROPERTY(BlueprintReadWrite, Category = "Area Arrays")
	TArray<AArea*> Areas;

	UPROPERTY(BlueprintReadWrite, Category = "Area Arrays")
	TArray<AArea*> Rooms;

	UPROPERTY(BlueprintReadWrite, Category = "Area Arrays")
	TArray<AArea*> Halls;

	TArray<EArea> halls_enum = { EArea::D_1F_Bridge_Hall, EArea::D_1F_E_Hall, EArea::D_1F_E_Stair, EArea::D_1F_W_Hall, EArea::D_1F_W_Stair, EArea::D_2F_Bridge_Hall, EArea::D_2F_E_Hall, EArea::D_2F_W_Hall, EArea::D_Basement_Stair, EArea::D_Basement, EArea::D_Garden };

	UFUNCTION(BlueprintCallable)
	void InitiateAreas();
};