#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class TESTTASK_API ABaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ABaseCharacter();

    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UFUNCTION(BlueprintCallable, Category = "Pickup")
    int32 GetCoinCollect() { return CoinCollect; }

    UFUNCTION(BlueprintCallable, Category = "Pickup")
    bool GetHaveKey() { return HaveKey; }

    UFUNCTION(BlueprintCallable, Category = "Pickup")
    void SetHaveKey(bool Key) { this->HaveKey = Key; }

    void AddCoin() { CoinCollect++; }

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
    bool HaveKey = false;

private:
    void MoveForward(float Amount);
    void MoveRight(float Amount);

    int32 CoinCollect = 0;
};
