#pragma once

//#include "SharedPointer.h"
#include "SceneEvent.h"
#include "PushSceneEvent.generated.h"


UCLASS()
class HOPE_API UPushSceneEvent : public USceneEvent {
  
public:
    GENERATED_BODY()
        UPushSceneEvent(const FObjectInitializer& ObjectInitializer);
    virtual ~UPushSceneEvent();
protected:
    UPushSceneEvent(){};

protected:
    virtual void OnTransOutFinished();
    virtual void OnTransInFinished();
public:
    virtual void         Execute() override;
};