#pragma once

#include "string"
#include "Blueprint/UserWidget.h"
#include "GameScene.generated.h"


class AGamePlayerController;
class UWidgetAnimation;
class USceneWidget;
class UWidgetAnimation;
class SceneEvent;
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



    virtual void PlayTransOutAnimation(const TSharedPtr<SceneEvent>& pSceneEvent);
    virtual void PlayTransInAnimation(const TSharedPtr<SceneEvent>& pSceneEvent);
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

    TWeakPtr<SceneEvent> SceneEventListenerWeakPtr;
};

