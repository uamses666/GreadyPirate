#include "TestTaskGameModeBase.h"
#include "Player/BaseCharacter.h"
#include "Player/TestTaskPlayerController.h"

ATestTaskGameModeBase::ATestTaskGameModeBase()
{
    DefaultPawnClass = ABaseCharacter::StaticClass();
    PlayerControllerClass = ATestTaskPlayerController::StaticClass();
}
