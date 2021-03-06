// Fill out your copyright notice in the Description page of Project Settings.

#include "No_Bark_Prototype2.h"
#include "Door.h"
#include "GameFramework/InputSettings.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshDoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	RootComponent = MeshDoorFrame;

	MeshDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	MeshDoor->SetupAttachment(RootComponent);

	BoxCollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollisionComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

