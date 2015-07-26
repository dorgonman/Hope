#include "Hope.h"
#include "scene/TitleScene.h"

// include
#include "Blueprint/UserWidget.h"
#include "UMG.h"

#include "WidgetAnimation.h"
#include "Engine/LocalPlayer.h"
#include "Engine/GameInstance.h"
#include "MovieScene.h"
#include "GamePlayerController.h"

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

    //static ConstructorHelpers::FClassFinder<UUserWidget> PutNameHere(TEXT("/Game/UMG/TitleScene/TitleSceneWBP"));
    // if (PutNameHere.Class) {
    // TitleSceneWidgetClass = PutNameHere.Class;

    // }



    //onLoadUILayer, assign value

    //if (TitleSceneWidgetClass) // Check if the Asset is assigned in the blueprint.
    //{
    //    // Create the widget and store it.
    //    TitleSceneWidget = CreateWidget<UUserWidget>(this, TitleSceneWidgetClass);

    //    // now you can use the widget directly since you have a referance for it.
    //    // Extra check to  make sure the pointer holds the widget.
    //    if (TitleSceneWidget)
    //    {
    //        //let add it to the view port
    //        TitleSceneWidget->AddToViewport();
    //    }
    //    UButton* btnStart = (UButton*)TitleSceneWidget->GetWidgetFromName(TEXT("BTN_START"));
    //    //if (btnStart)
    //    // btnStart->OnClicked.AddDynamic(this, &AMyPlayerController::StartGame);



    //    UWidgetBlueprintGeneratedClass* BGClass = Cast<UWidgetBlueprintGeneratedClass>(TitleSceneWidget->GetClass());
    //    if (BGClass){
    //        for (UWidgetAnimation* Animation : BGClass->Animations)
    //        {
    //            if (Animation->MovieScene)
    //            {

    //                UE_LOG(LogHope, Log, TEXT("test:%s"), *Animation->MovieScene->GetFName().ToString());
    //                // Find property with the same name as the template and assign the new widget to it.
    //                /* UObjectPropertyBase* Prop = FindField<UObjectPropertyBase>(WidgetBlueprintClass, Animation->MovieScene->GetFName());
    //                if (Prop)
    //                {
    //                Prop->SetObjectPropertyValue_InContainer(UserWidget, Anim);
    //                }*/
    //                //num =0 == loop
    //                //const UWidgetAnimation* InAnimation, float StartAtTime, int32 NumberOfLoops, EUMGSequencePlayMode::Type PlayMode
    //                TitleSceneWidget->PlayAnimation(Animation, 0.0F, 1);
    //            }
    //        }
    //    }


    //}
}
void UTitleScene::OnSceneVisible(){

}
void UTitleScene::OnExit(){


}
void UTitleScene::OnSceneDisable(){


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