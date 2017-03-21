// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "No_Bark_Prototype2GameModeBase.generated.h"


//enum to store the current state of gameplay
UENUM(BlueprintType)
enum class EBatteryPlayState
{
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};


/**
 * 
 */
UCLASS()
class NO_BARK_PROTOTYPE2_API ANo_Bark_Prototype2GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	// Sets default values for this Gamemode's properties
		ANo_Bark_Prototype2GameModeBase();
	
		virtual void Tick(float DeltaTime) override;

		/** Returns power needed to win - needed for the HUD */
		UFUNCTION(BlueprintPure, Category = "Power")
			float GetPowerToWin() const;

		virtual void BeginPlay() override;

		/** Returns the current playing state */
		UFUNCTION(BlueprintPure, Category = "Power")
			EBatteryPlayState GetCurrentState() const;

		/** Sets a new playing state */
		void SetCurrentState(EBatteryPlayState NewState);

protected:
	/**The rate at which the character loses power */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
		float DecayRate;

	/**The power needed to win the game */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
		float PowerToWin;

	///** The Widget class to use for our HUD screen */
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	//	TSubclassOf<class UUserWidget> HUDWidgetClass;

	/** The instance of the HUD */
	//UPROPERTY()
	//	class UUserWidget* CurrentWidget;

private:
	/**Keeps track of the current playing state */
	EBatteryPlayState CurrentState;

	TArray<class ASpawnVolume*> SpawnVolumeActors;

	/**Handle any function calls that rely upon changing the playing state of our game */
	void HandleNewState(EBatteryPlayState NewState);

};