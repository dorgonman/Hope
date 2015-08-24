#include "Hope.h"
#include "SceneManager.h"
#include "UMG.h"
#include "WidgetAnimation.h"
#include "scene/TitleScene.h"
#include "GamePlayerController.h"
#include "event/SceneEvent.h"

static USceneManager* s_instance = nullptr;
USceneManager::USceneManager(const FObjectInitializer& ObjectInitializer)
    : GameController(nullptr)
    , CurrentScene(nullptr)
{

}
USceneManager::~USceneManager(){

}
USceneManager* USceneManager::GetInstance(){
    if (nullptr == s_instance){
        s_instance = NewObject<USceneManager>();
        s_instance->AddToRoot();
    }
    return s_instance;
}

void USceneManager::Destroy(){
    if (s_instance){
        s_instance->RemoveFromRoot();
        s_instance = nullptr;
    }

}

void USceneManager::SetGameController(AGamePlayerController* pController) {
    GameController = pController;
}


void USceneManager::SetCurrentScene(UGameScene* pCurrentScene){
    ensureMsgf(pCurrentScene, TEXT("oops! SceneManager::SetCurrentScene()"));
    if (CurrentScene && CurrentScene->IsValidLowLevelFast()){
        CurrentScene->OnExit();
    }
    CurrentScene = pCurrentScene;
    if (!SceneStack.Contains(pCurrentScene)){
        SceneStack.Emplace(CurrentScene);
    }
}


void USceneManager::Tick(float dt){

    if (SceneEventArr.Num() > 0){
        auto pEvent = SceneEventArr[0];
        if (pEvent->IsFinished()){
            SceneEventArr.Remove(pEvent);
        }else{
            pEvent->Execute();
        
        } 
        return;
    }

    if (nullptr != CurrentScene && CurrentScene->IsValidLowLevel()){
        CurrentScene->Tick(dt);
    }
 

}


UWorld* USceneManager::GetWorld() const{
    if (GameController){
        return GameController->GetWorld();
    }

    return nullptr; 
}

void USceneManager::TryGarbageCollection(bool bIgnoreMemoryUsage){
    FPlatformMemory::DumpStats(*GLog);

    const float InvMB = 1.0f / 1024.0f / 1024.0f;
    auto stats = FPlatformMemory::GetStats();
    float availablePhysicalMB = stats.AvailablePhysical * InvMB;
    if (availablePhysicalMB < 100 || bIgnoreMemoryUsage){
        auto world = USceneManager::GetInstance()->GetWorld();
        if (world){
            //start try GC
            world->PerformGarbageCollectionAndCleanupActors();
        }
    }
}


void USceneManager::ClearSceneStack(){
    SceneStack.Empty();
}