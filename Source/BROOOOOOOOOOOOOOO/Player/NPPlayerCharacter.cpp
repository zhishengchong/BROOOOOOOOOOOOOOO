#include "Player/NPPlayerCharacter.h"
#include "Player/NPScanComponent.h"
#include "GameFramework/PlayerController.h"

ANPPlayerCharacter::ANPPlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // Initialize the Scanner
    ScanComponent = CreateDefaultSubobject<UNPScanComponent>(TEXT("ScannerComponent"));
}

void ANPPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ANPPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind Movement Axes
    PlayerInputComponent->BindAxis("MoveForward", this, &ANPPlayerCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ANPPlayerCharacter::MoveRight);

    // Bind Mouse Looking (Standard Unreal Engine Axis Names)
    PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
    PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
    
    // Bind Jump Action
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
}

void ANPPlayerCharacter::MoveForward(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        // Move in the direction the camera is facing
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void ANPPlayerCharacter::MoveRight(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        // Move relative to the camera's right side
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}