// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Engine/World.h"

/**
 * 
 */
class TOGETHER_API FunctionLib
{
public:
	FunctionLib();
	~FunctionLib();

	static FHitResult ForwardLineTrace(AActor* target, int tracedist);
};
