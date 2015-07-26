#pragma once

#include "string"
#include "Blueprint/UserWidget.h"
#include "GameScene.generated.h"

UCLASS()
class HOPE_API USceneWidget : public UUserWidget{
public:
    GENERATED_BODY()
    USceneWidget(const FObjectInitializer& ObjectInitializer);
    virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My New User Widget")
    FString MyNewWidgetName;
};

class AGamePlayerController;
class UWidgetAnimation;
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
    virtual UWidgetAnimation* GetWidgetAnimation(const FString& animeName);
protected:
    void SetSceneWidgetClass(const TCHAR* widgetPath);
    USceneWidget* GetSceneWidget();
private:
    TSubclassOf<class USceneWidget> SceneWidgetClass;
    // Variable to hold the widget After Creating it.
    //UPROPERTY()
    USceneWidget* SceneWidget;
};

