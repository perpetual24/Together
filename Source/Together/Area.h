// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AreaEnum.h"
#include "Engine/TriggerBox.h"
#include "Components/BoxComponent.h"
#include "Area.generated.h"

/**
 * 
 */
UCLASS()
class TOGETHER_API AArea : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	AArea()
	{
		box_extent = Cast<UBoxComponent>(GetCollisionComponent())->GetUnscaledBoxExtent();
	}

	FVector box_extent;

	UPROPERTY(BlueprintReadWrite)
	EArea AreaEnum;

	UFUNCTION(BlueprintCallable)
	void GetXYPoint(FVector& p_minus, FVector& p_plus);

	UFUNCTION(BlueprintCallable)
	void GetXYZPoint(FVector& p_minus, FVector& p_plus);

	UFUNCTION(BlueprintCallable)
	void ResizeXYPoint(float percent_x, float percent_y, FVector p_minus, FVector p_plus, FVector& resized_p_minus, FVector& resized_p_plus);

	UFUNCTION(BlueprintCallable)
	FVector RandomPointXY(float percent_x, float percent_y);
};
