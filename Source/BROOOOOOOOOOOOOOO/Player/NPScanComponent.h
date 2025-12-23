
#pragma once



#include "CoreMinimal.h"

#include "Components/ActorComponent.h"

#include "NPScanComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )

class BROOOOOOOOOOOOOOO_API UNPScanComponent : public UActorComponent

{

    GENERATED_BODY()



public: 

    // Sets default values for this component's properties

    UNPScanComponent();



    // The main function to trigger a scan - BlueprintCallable makes it show up in BP

    UFUNCTION(BlueprintCallable, Category = "Scanning")

    void PerformScan();



    // The distance the scanner can reach

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scanning")

    float ScanRadius = 2000.f;



protected:

    // Called when the game starts

    virtual void BeginPlay() override;

};