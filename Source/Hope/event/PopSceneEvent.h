#pragma once

//#include "SharedPointer.h"
#include "SceneEvent.h"
#include "PopSceneEvent.generated.h"


UCLASS()
class HOPE_API UPopSceneEvent : public USceneEvent {
  
public:
    GENERATED_BODY()
    UPopSceneEvent(const FObjectInitializer& ObjectInitializer);
    virtual ~UPopSceneEvent();
protected:
    UPopSceneEvent(){};

protected:
    virtual void OnTransOutFinished();
    virtual void OnTransInFinished();
public:
    virtual void         Execute() override;
};