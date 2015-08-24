#include "Hope.h"
#include "PushSceneEvent.h"
#include "manager/SceneManager.h"
#include "GamePlayerController.h"
#include "scene/GameScene.h"



UPushSceneEvent::UPushSceneEvent(const FObjectInitializer& ObjectInitializer){

}

UPushSceneEvent::~UPushSceneEvent(){

}



void  UPushSceneEvent::Execute(){
    Super::Execute();


}

void UPushSceneEvent::OnTransOutFinished(){
    Super::OnTransOutFinished();


}
void UPushSceneEvent::OnTransInFinished(){
    Super::OnTransInFinished();

}