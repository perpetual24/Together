// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Camera/CameraShake.h"
#include "GameInst.h"
#include "Components/AudioComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FuncLib.generated.h"

UCLASS()
class TOGETHER_API UFuncLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void PlayFootstepSound(AActor* target, UPhysicalMaterial* phymat, float volume);
};