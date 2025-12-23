#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "NPGameStateBase.generated.h" // MUST match the filename

UCLASS()
class BROOOOOOOOOOOOOOO_API ANPGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ANPGameState();

	UPROPERTY(BlueprintReadOnly)
	bool bIsTargetRevealed;
};