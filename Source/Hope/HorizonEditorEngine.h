#pragma once
 
#include "UnrealEd.h"
#include "HorizonEditorEngine.generated.h"
 
 UCLASS()
 class UHorizonEditorEngine : public UUnrealEdEngine
 {
     GENERATED_UCLASS_BODY()
 
 
     // When engine starts
     void Init(class IEngineLoop* InEngineLoop) override;
     // Close engine
     void PreExit() override;
 };