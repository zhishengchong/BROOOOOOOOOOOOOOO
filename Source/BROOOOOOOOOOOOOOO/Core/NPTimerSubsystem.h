#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TimerManager.h"
#include "NPTimerSubsystem.generated.h"

UCLASS()
class BROOOOOOOOOOOOOOO_API UNPTimerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void StartTimer(float InSeconds);

	UFUNCTION(BlueprintCallable)
	float GetRemainingTime() const;

protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

private:
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	float RemainingTime;

	FTimerHandle TimerHandle;

	UFUNCTION()
	void TickTimer();
};
