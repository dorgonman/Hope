#pragma once

#include "string"
#include "Blueprint/UserWidget.h"
#include "GameScene.generated.h"


class AGamePlayerController;
class UWidgetAnimation;
class USceneWidget;
class UWidgetAnimation;
class USceneEvent;

//game scene for render: 1. UI 2. 3D...and other render task
UCLASS()
class HOPE_API UGameScene : public UObject
{
public:
    GENERATED_BODY()
    UGameScene(const FObjectInitializer& ObjectInitializer);
    virtual ~UGameScene();
public:
    virtual void Tick(float dt);
public://scene Callback
    virtual void OnEnter(AGamePlayerController* pController);
    virtual void OnSceneVisible();
    virtual void OnSceneDisable();
    virtual void OnExit();



    virtual void PlayTransOutAnimation(USceneEvent* pSceneEvent);
    virtual void PlayTransInAnimation(USceneEvent* pSceneEvent);
    virtual UWidgetAnimation* GetWidgetAnimation(const FString& animeName);

protected:
    UFUNCTION()
    virtual void OnAnimationFinished(const FString& animeName);
protected:
    void SetSceneWidgetClass(const TCHAR* widgetPath);
    USceneWidget* GetSceneWidget();
private:
    UPROPERTY()
    TSubclassOf<class UGameWidget> SceneWidgetClass;
    // Variable to hold the widget After Creating it.
    UPROPERTY()
    USceneWidget* SceneWidget;

    TWeakObjectPtr<class USceneEvent> SceneEventListenerWeakPtr;
    //TWeakPtr<USceneEvent> SceneEventListenerWeakPtr;
};

