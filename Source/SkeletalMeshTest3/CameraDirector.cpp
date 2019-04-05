// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraDirector.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// m_CameraPointers = TArray<AActor*>();
}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// const float TimeBetweenCameraChanges = 2.0f;
	// const float SmoothBlendTime = 0.75f;
	m_TimeToNextCameraChange -= DeltaTime;


	if (m_TimeToNextCameraChange <= 0.0f)
	{

		// Find the actor that handles control for the local player.
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			// get currentCamera from TArray
			FCameraStruct currentCameraStruct = m_CameraPointers[m_CurrentCameraCounter];

			m_TimeToNextCameraChange += currentCameraStruct.timeBetweenCameraChanges;
			 
			if ((OurPlayerController->GetViewTarget() != currentCameraStruct.ptrToCamera) && (currentCameraStruct.ptrToCamera != nullptr))
			{
				// Blend smoothly to camera two. 
				OurPlayerController->SetViewTargetWithBlend(currentCameraStruct.ptrToCamera, currentCameraStruct.smoothBlendTime);
			} 
			 
			// advance current camera: 
			++m_CurrentCameraCounter;
			if (m_CurrentCameraCounter >= m_CameraPointers.Num()) { m_CurrentCameraCounter = 0; }
		}
	}
}

