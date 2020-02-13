// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "GameFrameWork/Actor.h"
#include "FunctionLib.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/SceneComponent.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOGETHER_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPhysicsHandleComponent* PhysicsHandle;
	USceneComponent* PhysicsHandlePos;

	UFUNCTION(BlueprintCallable)
		void InitiateGrabber(UPhysicsHandleComponent* handle, USceneComponent* handlepos);

	UFUNCTION(BlueprintCallable)
		bool Grab();

	UFUNCTION(BlueprintCallable)
		void Release();

	UFUNCTION(BlueprintCallable)
		float GetInterpSpeedByMass();

	UFUNCTION(BlueprintCallable)
		float GetMoveSpeedByMass();
};
