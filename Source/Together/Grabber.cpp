// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawDebugHelpers.h"
#include "Grabber.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	PhysicsHandle->SetTargetLocationAndRotation(PhysicsHandlePos->GetComponentLocation(), PhysicsHandlePos->GetComponentRotation());
}

void UGrabber::InitiateGrabber(UPhysicsHandleComponent* handle, USceneComponent* handlepos)
{
	PhysicsHandle = handle;
	PhysicsHandlePos = handlepos;
}

void UGrabber::Grab()
{
	auto TracedComponent = FunctionLib::ForwardLineTrace(GetOwner(), 150).GetComponent();
	FVector TargetLoc;
	FRotator TargetRot;
	
	PhysicsHandle->GetTargetLocationAndRotation(TargetLoc, TargetRot);
	PhysicsHandle->GrabComponentAtLocationWithRotation(TracedComponent, FName("None"), TargetLoc, TargetRot);
}

void UGrabber::Release()
{
	PhysicsHandle->ReleaseComponent();
}