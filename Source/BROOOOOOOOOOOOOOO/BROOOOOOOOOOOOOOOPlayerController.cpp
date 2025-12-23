// Copyright Epic Games, Inc. All Rights Reserved.


#include "BROOOOOOOOOOOOOOOPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "BROOOOOOOOOOOOOOOCameraManager.h"
#include "Blueprint/UserWidget.h"
#include "BROOOOOOOOOOOOOOO.h"
#include "Widgets/Input/SVirtualJoystick.h"

ABROOOOOOOOOOOOOOOPlayerController::ABROOOOOOOOOOOOOOOPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = ABROOOOOOOOOOOOOOOCameraManager::StaticClass();
}

void ABROOOOOOOOOOOOOOOPlayerController::BeginPlay()
{
	Super::BeginPlay();

	
	// only spawn touch controls on local player controllers
	if (SVirtualJoystick::ShouldDisplayTouchInterface() && IsLocalPlayerController())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(LogBROOOOOOOOOOOOOOO, Error, TEXT("Could not spawn mobile controls widget."));

		}

	}
}

void ABROOOOOOOOOOOOOOOPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Context
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!SVirtualJoystick::ShouldDisplayTouchInterface())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
	
}
