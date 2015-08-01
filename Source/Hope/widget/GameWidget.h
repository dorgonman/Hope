#pragma once
#include <functional>
#include "Blueprint/UserWidget.h"
#include "GameWidget.generated.h"

UCLASS()
class HOPE_API UGameWidget : public UUserWidget{
public:
    GENERATED_BODY()
    UGameWidget(const FObjectInitializer& ObjectInitializer);
    virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My New User Widget")
    FString MyNewWidgetName;
public:
    std::function<void(const FString&)> OnAnimationFinishedCallback;
};



UCLASS()
class HOPE_API USceneWidget : public UGameWidget{
public:
    GENERATED_BODY()
    USceneWidget(const FObjectInitializer& ObjectInitializer);
    virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

};
