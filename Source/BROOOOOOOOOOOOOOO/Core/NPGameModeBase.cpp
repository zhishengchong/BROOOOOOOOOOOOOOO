#include "NPGameModeBase.h"
#include "Core/NPTimerSubsystem.h" 
#include "Core/NPGameStateBase.h"  
#include "Kismet/GameplayStatics.h"

ANPGameModeBase::ANPGameModeBase()
{
	bTargetEliminated = false;
	GameStateClass = ANPGameState::StaticClass();
}


void ANPGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// The compiler likes this 'if' style for safety
	if (UNPTimerSubsystem* TimerSub = GetGameInstance()->GetSubsystem<UNPTimerSubsystem>())
	{
		TimerSub->StartTimer(10.0f); // Start the 5-minute mission
		UE_LOG(LogTemp, Warning, TEXT("MISSION STARTED: Timer is running."));
	}
}

void ANPGameModeBase::OnTargetEliminated()
{
	bTargetEliminated = true;

	if (ANPGameState* GS = GetGameState<ANPGameState>())
	{
		GS->bIsTargetRevealed = true;
	}

	UE_LOG(LogTemp, Warning, TEXT("Target eliminated"));
}


void ANPGameModeBase::OnPlayerExtracted()
{
	if (bTargetEliminated)
	{
		UE_LOG(LogTemp, Warning, TEXT("MISSION SUCCESS"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Extracted without killing target"));
	}
}

void ANPGameModeBase::OnMissionFailed()
{
	// Logic for what happens when time runs out
	UE_LOG(LogTemp, Error, TEXT("GAME OVER - YOU RAN OUT OF TIME"));
    
	// Example: Restart the level after 3 seconds
	// UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
}
