// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class NO_BARK_PROTOTYPE2_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	/**Door Frame Mesh */
	UPROPERTY(EditAnywhere, Category = Mesh)
		class UStaticMeshComponent* MeshDoorFrame;
	/**Door Mesh*/
	UPROPERTY(EditAnywhere, Category = Mesh)
		class UStaticMeshComponent* MeshDoor;

	/**Box Collision */
	UPROPERTY(EditAnywhere, Category = Mesh)
		class UBoxComponent* BoxCollisionComponent;

	
};
