#include "AI/NPRogueTargetCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Core/NPGameModeBase.h"

// Sets default values
ANPRogueTargetCharacter::ANPRogueTargetCharacter()
{
	// Disable ticking to save performance since this AI just waits to be scanned
	PrimaryActorTick.bCanEverTick = false;
	bIsDead = false;
}

// Called when the game starts or when spawned
void ANPRogueTargetCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ANPRogueTargetCharacter::Die()
{
	// Prevent the function from running twice if called multiple times
	if (bIsDead) return;

	bIsDead = true;

	// 1. Notify the GameMode so it can reveal the extraction zone
	if (ANPGameModeBase* GM = Cast<ANPGameModeBase>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		GM->OnTargetEliminated();
		UE_LOG(LogTemp, Warning, TEXT("Target AI: Notifying GameMode of elimination."));
	}

	// 2. Destroy the actor from the scene
	Destroy();
}