#pragma once

#include "GameFramework/PlayerController.h"
#include "TitleScene.generated.h"


class AGamePlayerController;
UCLASS()
class HOPE_API UTitleScene : public UObject
{
public:
    GENERATED_BODY()
    UTitleScene(const FObjectInitializer& ObjectInitializer);
    void Tick(float dt);
public://scene Callback
    virtual void OnEnter(AGamePlayerController* pController);
    virtual void OnSceneVisible();
    virtual void OnExit();
    virtual void OnSceneDisable();
private:
    TSubclassOf<class UUserWidget> SceneWidgetClass;
    // Variable to hold the widget After Creating it.
    UUserWidget* SceneWidget;
};

