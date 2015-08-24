#include "Hope.h"
#include "PopSceneEvent.h"
#include "manager/SceneManager.h"
#include "GamePlayerController.h"
#include "scene/GameScene.h"



UPopSceneEvent::UPopSceneEvent(const FObjectInitializer& ObjectInitializer){

}

UPopSceneEvent::~UPopSceneEvent(){

}



void  UPopSceneEvent::Execute(){
    Super::Execute();
}

void UPopSceneEvent::OnTransOutFinished(){
    Super::OnTransOutFinished();


}
void UPopSceneEvent::OnTransInFinished(){
    Super::OnTransInFinished();

}


