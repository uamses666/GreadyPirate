#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TTCoin.generated.h"

class USphereComponent;
class USoundCue;

UCLASS()
class TESTTASK_API ATTCoin : public AActor
{
    GENERATED_BODY()

public:
    ATTCoin();

    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category = "Pickup")
    int32 GetTotalCoins() { return TotalCoins; }

protected:
    virtual void BeginPlay() override;
    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
    virtual void PostInitializeComponents() override;

    UPROPERTY(VisibleAnywhere, Category = "Pickup")
    USphereComponent* CollisionComponent;

    UPROPERTY(EditAnywhere, Category = "Sound")
    USoundCue* PickupSound;

private:
    float RotationYaw = 0.0f;

    void GenerateRotationYaw();

    static int32 CoinCount;
    static int32 TotalCoins;
};
