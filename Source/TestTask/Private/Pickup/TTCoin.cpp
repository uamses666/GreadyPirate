#include "Pickup/TTCoin.h"
#include "Components/SphereComponent.h"
#include "Player/BaseCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

DEFINE_LOG_CATEGORY_STATIC(LogCoinPickup, All, All);

int32 ATTCoin::CoinCount = -1;
int32 ATTCoin::TotalCoins = 0;

ATTCoin::ATTCoin()
{
    PrimaryActorTick.bCanEverTick = true;

    CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(50.0f);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    SetRootComponent(CollisionComponent);
}

void ATTCoin::PostInitializeComponents() {
    Super::PostInitializeComponents();
    CoinCount = -1;
}

void ATTCoin::BeginPlay()
{
    Super::BeginPlay();
    GenerateRotationYaw();
    CoinCount++;
    TotalCoins = CoinCount;
}

void ATTCoin::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    AddActorLocalRotation(FRotator(0.0f, RotationYaw, 0.0f));
}

void ATTCoin::GenerateRotationYaw()
{
    const auto Direction = FMath::RandBool() ? 1.0f : -1.0f;
    RotationYaw = FMath::RandRange(1.0f, 2.0f) * Direction;
}

void ATTCoin::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);

    const auto BaseCharacter = Cast<ABaseCharacter>(OtherActor);
    if (!BaseCharacter) return;

    BaseCharacter->AddCoin();
    if (BaseCharacter->GetCoinCollect() >= TotalCoins)
    {
        BaseCharacter->SetHaveKey(true);
    }

    CoinCount--;
    UGameplayStatics::PlaySoundAtLocation(GetWorld(), PickupSound, GetActorLocation());
    Destroy();
}



