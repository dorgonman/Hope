#include "Hope.h"
#include "scene/TitleScene.h"

// include
#include "Blueprint/UserWidget.h"
#include "UMG.h"


#include "Engine/LocalPlayer.h"
#include "Engine/GameInstance.h"
#include "MovieScene.h"
#include "GamePlayerController.h"
#include "WidgetAnimation.h"
/*TitleScene::TitleScene(){
    static ConstructorHelpers::FClassFinder<UUserWidget> PutNameHere(TEXT("/Game/UMG/TitleScene/TitleSceneWBP"));
    if (PutNameHere.Class) {
        SceneWidgetClass = PutNameHere.Class;
    }
}
TitleScene::~TitleScene(){

}*/
UTitleScene::UTitleScene(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

    
    this->SetSceneWidgetClass(TEXT("/Game/UMG/TitleScene/TitleSceneWBP"));
    
}

void UTitleScene::Tick(float dt){
    Super::Tick(dt);


}

void UTitleScene::OnEnter(AGamePlayerController* pController){
    Super::OnEnter(pController);
    //initRequest
    //initUI && execute animation

    UButton* btnStart = dynamic_cast<UButton*>(GetSceneWidget()->GetWidgetFromName(TEXT("BTN_START")));
    if (btnStart){
        btnStart->OnClicked.AddDynamic(this, &UTitleScene::StartGame);
    }
}
void UTitleScene::OnSceneVisible(){

}
void UTitleScene::OnExit(){


}
void UTitleScene::OnSceneDisable(){


}

void UTitleScene::PlayTransInAnimation(){
   

    //num =0 == loop
    //const UWidgetAnimation* InAnimation, float StartAtTime, int32 NumberOfLoops, EUMGSequencePlayMode::Type PlayMode
    auto animeName = FString("begin_enter");
    auto animation = GetWidgetAnimation(animeName);
    
    GetSceneWidget()->PlayAnimation(animation, 0.0F, 1);
 
}
void UTitleScene::PlayTransOutAnimation(){
    //GetSceneWidget()->
    //UWidgetBlueprintGeneratedClass* BGClass = Cast<UWidgetBlueprintGeneratedClass>(GetSceneWidget()->GetClass());
    //if (BGClass){
        //BGClass->
        //BGClass->Animations->
        /*for (UWidgetAnimation* Animation : BGClass->Animations){
                if (animation->moviescene)
                {

                   // ue_log(loghope, log, text("test:%s"), *animation->moviescene->getfname().tostring());
                    // find property with the same name as the template and assign the new widget to it.
                    uobjectpropertybase* prop = findfield<uobjectpropertybase>(widgetblueprintclass, animation->moviescene->getfname());
                    if (prop)
                    {
                    prop->setobjectpropertyvalue_incontainer(userwidget, anim);
                    }
                    //num =0 == loop
                    //const uwidgetanimation* inanimation, float startattime, int32 numberofloops, eumgsequenceplaymode::type playmode
                   // titlescenewidget->playanimation(animation, 0.0f, 1);
                }
            }
        }*/


   // }


}

void UTitleScene::StartGame(){
    UE_LOG(LogHope, Log, TEXT("StartGame:"));
}