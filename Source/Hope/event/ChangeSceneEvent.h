#pragma once

//#include "SharedPointer.h"
#include "SceneEvent.h"
#include "ChangeSceneEvent.generated.h"


UCLASS()
class HOPE_API UChangeSceneEvent : public USceneEvent {
  
public:
    GENERATED_BODY()
    UChangeSceneEvent(const FObjectInitializer& ObjectInitializer);
    virtual ~UChangeSceneEvent();
protected:
    UChangeSceneEvent(){};

    virtual void         Execute() override;
};