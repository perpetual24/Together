// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"

#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red, text)

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

	PC = Cast<APlayer_C>(UGameplayStatics::GetPlayerController(this, 0));
}

void UGrabber::InitiateGrabber(UPhysicsHandleComponent* handle, USceneComponent* handlepos)
{
	PhysicsHandle = handle;
	PhysicsHandlePos = handlepos;
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PhysicsHandle)
	{
		PhysicsHandle->SetTargetLocationAndRotation(PhysicsHandlePos->GetComponentLocation(), PhysicsHandlePos->GetComponentRotation());
	}

	else
	{
		print("Physics Handle Not Found");
	}
}

bool UGrabber::Grab()
{
	FHitResult Hit = UFuncLib::LineTraceWithDir(GetOwner(), EDirection::Forward, 200);
	UPrimitiveComponent* TracedComponent = Hit.GetComponent();

	FVector TargetLoc;
	FRotator TargetRot;

	if (TracedComponent)
	{
		if (PhysicsHandle)
		{
			PhysicsHandle->GetTargetLocationAndRotation(TargetLoc, TargetRot);
			PhysicsHandle->GrabComponentAtLocationWithRotation(TracedComponent, FName("None"), TargetLoc, TargetRot);
		}

		else
		{
			print("Physics Handle Not Found");
		}

		if (PC)
		{
			PC->SetPitchLimitDuringGrab();
		}

		else
		{
			print("Player Controller Not Found");
		}

		return true;
	}

	else
	{
		return false;
	}
}

void UGrabber::Release()
{
	if (PhysicsHandle)
	{
		if (PhysicsHandle->GetGrabbedComponent())
		{
			PhysicsHandle->ReleaseComponent();

			if (PC)
			{
				PC->SetPitchLimitToDefault();
			}
			else
			{
				print("Player Controller Not Found");
			}
		}

		else
		{
			print("Grabbed Component Not Found");
		}
	}

	else
	{
		print("Physics Handle Not Found");
	}
	
}

float UGrabber::GetCameraSpeedByMass()
{
	if (PhysicsHandle)
	{
		float mass = PhysicsHandle->GetGrabbedComponent()->GetMass();
		float speed = -0.3909 * log(mass) + 3.4291;

		return FMath::Clamp(speed, 0.1f, 1.0f);
	}
	
	else
	{
		print("Physics Handle Not Found");

		return 1.0f;
	}
}

float UGrabber::GetMoveSpeedByMass()
{
	if (PhysicsHandle)
	{
		float mass = PhysicsHandle->GetGrabbedComponent()->GetMass();
		float speed = -0.1086 * log(mass) + 1.1747;

		return FMath::Clamp(speed, 0.25f, 0.5f);
	}

	else
	{
		print("Physics Handle Not Found");

		return 0.5f;
	}
}