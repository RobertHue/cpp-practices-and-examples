// Fill out your copyright notice in the Description page of Project Settings.

#include "NewSkeletalMeshComponent.h"



// Sets default values for this component's properties
UNewSkeletalMeshComponent::UNewSkeletalMeshComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsInitializeComponent = true;	// If true, we call the virtual InitializeComponent
	bAutoActivate = true;		// Whether the component is activated at creation or must be explicitly activated.
	PrimaryComponentTick.bCanEverTick = true;	// If false, this tick function will never be registered and will never tick. Only settable in defaults.
	  
	// ...
	// UE_LOG(LogTemp, Warning, TEXT("hallo"));
}

 
// Called when the game starts
void UNewSkeletalMeshComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));

}


// Called every frame
void UNewSkeletalMeshComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	// ...
	static int count = 0;
	++count; 
	if (count % 100 == 0) {
		count = 0;
		UE_LOG(LogTemp, Warning, TEXT("TickComponent"));
	}
}


