#include "Hope.h"
#include "HorizonEngine.h"
#include "manager/SceneManager.h"
UHorizonEngine::UHorizonEngine(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{}
 
void UHorizonEngine::Init(class IEngineLoop* InEngineLoop)
{
    Super::Init(InEngineLoop);
}
 
void UHorizonEngine::PreExit()
{
    Super::PreExit();
}

void UHorizonEngine::FinishDestroy(){
    SceneManager::Destroy();
    Super::FinishDestroy();
}