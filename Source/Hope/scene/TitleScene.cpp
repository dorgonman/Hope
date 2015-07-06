#include "Hope.h"
#include "scene/TitleScene.h"

TitleScene::TitleScene(){
    static ConstructorHelpers::FClassFinder<UUserWidget> PutNameHere(TEXT("/Game/UMG/TitleScene/TitleSceneWBP"));
    if (PutNameHere.Class) {
        SceneWidgetClass = PutNameHere.Class;
    }
}
TitleScene::~TitleScene(){

}


void TitleScene::Tick(float dt){


}

void TitleScene::OnEnter(){
    //initRequest
    //initUI && execute animation


    //onLoadUILayer, assign value
}
void TitleScene::OnSceneVisible(){

}
void TitleScene::OnExit(){


}
void TitleScene::OnSceneDisable(){


}