#include "Core/NPTimerSubsystem.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"    
#include "Core/NPGameModeBase.h"     

void UNPTimerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	RemainingTime = 0.f;
}

void UNPTimerSubsystem::StartTimer(float InSeconds)
{
	RemainingTime = InSeconds;

	if (UWorld* World = GetWorld())
	{
		FTimerDelegate TimerDel;
		TimerDel.BindUFunction(this, FName("TickTimer"));

		World->GetTimerManager().SetTimer(
			TimerHandle,
			TimerDel,
			1.0f,
			true
		);
	}

	UE_LOG(LogTemp, Warning, TEXT("Timer started: %.0f seconds"), RemainingTime);
}

void UNPTimerSubsystem::TickTimer()
{
	RemainingTime--;

	if (RemainingTime <= 0.f)
	{
		// 1. Stop the timer
		if (UWorld* World = GetWorld())
		{
			World->GetTimerManager().ClearTimer(TimerHandle);
		}

		// 2. TELL THE GAMEMODE THE MISSION FAILED
		if (ANPGameModeBase* GM = Cast<ANPGameModeBase>(UGameplayStatics::GetGameMode(GetWorld())))
		{
			GM->OnMissionFailed(); // We need to make sure this function exists!
			UE_LOG(LogTemp, Error, TEXT("TIMER EXPIRED: Mission Failed."));
		}
	}
}

float UNPTimerSubsystem::GetRemainingTime() const
{
	return RemainingTime;
}
