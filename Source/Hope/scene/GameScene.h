#pragma once

#include "string"
#include "GameScene.generated.h"



class AGamePlayerController;
class UUserWidget;

UCLASS()
class HOPE_API UGameScene : public UObject
{
public:
    GENERATED_BODY()
    UGameScene(const FObjectInitializer& ObjectInitializer);
public:
    virtual void Tick(float dt);
public://scene Callback
    virtual void OnEnter(AGamePlayerController* pController);
    //virtual void OnSceneVisible();
    virtual void OnExit();
    //virtual void OnSceneDisable();


    virtual void PlayTransOutAnimation(){};
    virtual void PlayTransInAnimation(){};
protected:
    void SetSceneWidgetClass(const TCHAR* widgetPath);
    UUserWidget* GetSceneWidget();
private:
    TSubclassOf<class UUserWidget> SceneWidgetClass;
    // Variable to hold the widget After Creating it.
    UPROPERTY()
    UUserWidget* SceneWidget;
};

