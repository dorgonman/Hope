#pragma once
#include <functional>
#include "Blueprint/UserWidget.h"
#include "GameWidget.generated.h"



DECLARE_DYNAMIC_DELEGATE_OneParam(FAnimationFinishedDelegate, const FString&, animeName);

UCLASS()
class HOPE_API UGameWidget : public UUserWidget{
public:
    GENERATED_BODY()
    UGameWidget(const FObjectInitializer& ObjectInitializer);
    virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My New User Widget")
    FString MyNewWidgetName;
    //DECLARE_DELEGATE_OneParam(FAnimationFinishedDelegate, const FString&);
    
public:
   
    UPROPERTY()
    FAnimationFinishedDelegate OnAnimationFinishedDelegate;
};


//DECLARE_DYNAMIC_DELEGATE_OneParam(FAnimationFinishedDelegate2, UGameWidget*, const FString&);


UCLASS()
class HOPE_API USceneWidget : public UGameWidget{
public:
    GENERATED_BODY()
    USceneWidget(const FObjectInitializer& ObjectInitializer);
    virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

};
