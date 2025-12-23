#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPPlayerCharacter.generated.h"

class UNPScanComponent;

UCLASS()
class BROOOOOOOOOOOOOOO_API ANPPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ANPPlayerCharacter();

	/** The Scanner Component attached to this player */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Scanner", meta = (AllowPrivateAccess = "true"))
	UNPScanComponent* ScanComponent;

protected:
	virtual void BeginPlay() override;

	/** Movement Functions */
	void MoveForward(float Value);
	void MoveRight(float Value);

public:
	/** Called to bind functionality to input (WASD and Mouse) */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};