#pragma once
 
#include "Engine/GameEngine.h"
#include "HorizonEngine.generated.h"
 
 UCLASS()
 class UHorizonEngine : public UGameEngine
 {
     GENERATED_UCLASS_BODY()
 
 
     // When engine starts
     virtual void Init(class IEngineLoop* InEngineLoop) override;
     // Close engine
     virtual void PreExit() override;
     virtual void FinishDestroy() override;
 };