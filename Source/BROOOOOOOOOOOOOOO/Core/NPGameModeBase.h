#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NPGameModeBase.generated.h"

UCLASS()
class BROOOOOOOOOOOOOOO_API ANPGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANPGameModeBase();

	// Called when the Rogue AI is destroyed
	UFUNCTION(BlueprintCallable)
	void OnTargetEliminated();

	// Called when player enters extraction zone
	UFUNCTION(BlueprintCallable)
	void OnPlayerExtracted();
	
	UFUNCTION(BlueprintCallable)
	void OnMissionFailed();

protected:
	virtual void BeginPlay() override;

private:
	bool bTargetEliminated;
};
