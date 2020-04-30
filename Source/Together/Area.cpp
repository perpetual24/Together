// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/UnrealMathUtility.h"
#include "Area.h"

void AArea::GetXYPoint(FVector& p_minus, FVector& p_plus)
{
	auto box_extent = Cast<UBoxComponent>(GetCollisionComponent())->GetUnscaledBoxExtent();
	FVector arealoc = GetActorLocation();

	p_minus = arealoc + (box_extent * -1);
	p_plus = arealoc + FVector(box_extent.X, box_extent.Y, box_extent.Z * -1);
}

void AArea::ResizeXYPoint(float percent_x, float percent_y, FVector p_minus, FVector p_plus, FVector& resized_p_minus, FVector& resized_p_plus)
{
	float x_dist = p_plus.X - p_minus.X;
	float y_dist = p_plus.Y - p_minus.Y;

	FVector addV(0.5 * x_dist * (1 - percent_x), 0.5 * y_dist * (1 - percent_y), 0);

	resized_p_minus = p_minus + addV;
	resized_p_plus = p_plus - addV;
}

FVector AArea::RandomPointXY(float percent_x, float percent_y)
{
	FVector p1, p2;
	FVector rp1, rp2;

	GetXYPoint(p1, p2);
	ResizeXYPoint(percent_x, percent_y, p1, p2, rp1, rp2);

	auto x = FMath::RandRange(rp1.X, rp2.X);
	auto y = FMath::RandRange(rp1.Y, rp2.Y);
	auto z = FMath::RandRange(rp1.Z, rp2.Z);

	return FVector(x, y, z);
}