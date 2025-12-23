#include "Player/NPScanComponent.h"

#include "Kismet/GameplayStatics.h"

#include "GameFramework/Actor.h"



// Sets default values

UNPScanComponent::UNPScanComponent()

{

    // We don't need this component to tick every frame

    PrimaryComponentTick.bCanEverTick = false; 

}



void UNPScanComponent::BeginPlay()

{

    Super::BeginPlay();

}



void UNPScanComponent::PerformScan()

{

    TArray<AActor*> FoundActors;

    

    // This searches the entire world for any Actor with the tag "ScanTarget"

    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("ScanTarget"), FoundActors);



    UE_LOG(LogTemp, Warning, TEXT("Scanning... Found %d potential targets."), FoundActors.Num());



    for (AActor* Target : FoundActors)

    {

       if (Target)

       {

          float Distance = FVector::Dist(GetOwner()->GetActorLocation(), Target->GetActorLocation());

            

          // If the target is within our set radius

          if (Distance <= ScanRadius) 

          {

             UE_LOG(LogTemp, Warning, TEXT("Scanner found: %s at distance: %f"), *Target->GetName(), Distance);

                

             // You can add logic here to highlight the target or update the HUD

          }

       }

    }

}