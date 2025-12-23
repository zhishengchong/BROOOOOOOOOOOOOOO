#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPRogueTargetCharacter.generated.h"

/**
 * AI Target Character for the Neon Pursuit mission.
 * This class handles its own destruction and notifies the GameMode.
 */
UCLASS()
class BROOOOOOOOOOOOOOO_API ANPRogueTargetCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPRogueTargetCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	/** * Call this function to kill the AI. 
	 * BlueprintCallable allows us to call this from the "Delay" node in your Blueprint.
	 */
	UFUNCTION(BlueprintCallable, Category = "AI Logic")
	void Die();

private:
	/** Internal flag to prevent multiple Die() calls */
	bool bIsDead;
};