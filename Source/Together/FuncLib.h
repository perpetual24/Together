// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Camera/CameraShake.h"
#include "GameInst.h"
#include "Components/AudioComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Area.h"
#include "Components/BoxComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FuncLib.generated.h"

UCLASS()
class TOGETHER_API UFuncLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void PlayFootstepSound(AActor* target, UPhysicalMaterial* phymat, float volume);

	UFUNCTION(BlueprintCallable)
	static FVector RandomVector(FVector from, FVector to);

	UFUNCTION(BlueprintCallable)
	static FRotator RandomRotator(FRotator from, FRotator to);

	//TODO: Will be Moved to SpawnActor Class
	UFUNCTION(BlueprintCallable)
	static AActor* SpawnActorWithZCorrection(AActor* target, TSubclassOf<class AActor> actorclass, FVector loc, FRotator rot);

	UFUNCTION(BlueprintCallable)
	static AArea* GetAreaClass(AActor* Actor, EArea FindAreaEnum, int index, bool random);

	UFUNCTION(BlueprintCallable)
	static TArray<AArea*> GetAreaClasses(AActor* Actor, EArea FindAreaEnum);

	UFUNCTION(BlueprintCallable)
	static AArea* GetAreaClassFromVector(AActor* Actor, FVector vector);

	//TODO: Will be Moved to Doll_AI Class
	UFUNCTION(BlueprintCallable)
	static float GetSoundStrength(float stimulus_strength, FVector impulser, FVector receiver, float multiplier = 1.0f);

	UFUNCTION(BlueprintCallable)
	static bool isVectorInArea(FVector vector, AArea* area);
};