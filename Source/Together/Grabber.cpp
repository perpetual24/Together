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

bool UGrabber::Grab()
{
	UPrimitiveComponent* TracedComponent = FunctionLib::ForwardLineTrace(GetOwner(), 200).GetComponent();
	FVector TargetLoc;
	FRotator TargetRot;

	if (IsValid(TracedComponent))
	{
		if (TracedComponent->GetMass() >= 5000)
		{
			TracedComponent->SetConstraintMode(EDOFMode::XYPlane);
		}

		PhysicsHandle->GetTargetLocationAndRotation(TargetLoc, TargetRot);
		PhysicsHandle->GrabComponentAtLocationWithRotation(TracedComponent, FName("None"), TargetLoc, TargetRot);

		return true;
	}

	else
	{
		return false;
	}
}

void UGrabber::Release()
{
	if (IsValid(PhysicsHandle->GetGrabbedComponent()))
	{
		PhysicsHandle->GetGrabbedComponent()->SetConstraintMode(EDOFMode::Default);

		PhysicsHandle->ReleaseComponent();
	}
}

float UGrabber::GetInterpSpeedByMass()
{
	float mass = PhysicsHandle->GetGrabbedComponent()->GetMass();

	return (-3.4744 * log(mass) + 31.592);
}

float UGrabber::GetMoveSpeedByMass()
{
	float mass = PhysicsHandle->GetGrabbedComponent()->GetMass();

	return (-0.1086 * log(mass) + 1.1747);
}