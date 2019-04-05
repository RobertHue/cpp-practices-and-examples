// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraDirector.generated.h"

USTRUCT()
struct FCameraStruct {
	GENERATED_BODY()
		 
	UPROPERTY(EditAnywhere)
	AActor* ptrToCamera;

	UPROPERTY(EditAnywhere)
	float timeBetweenCameraChanges;

	UPROPERTY(EditAnywhere)
	float smoothBlendTime;
};  


UCLASS()
class SKELETALMESHTEST3_API ACameraDirector : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties 
	ACameraDirector();

protected:
	// Called when the game starts or when spawned 
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private: 
	UPROPERTY(EditAnywhere)	// UPROPERTY-Macro makes our variables visible to UE4; and not be reset...
		TArray<FCameraStruct> m_CameraPointers;	// EditAnywhere allows us to set the Cameras inside the Unreal Editor
	 
	int m_CurrentCameraCounter = 0;

	float m_TimeToNextCameraChange;
	
};
