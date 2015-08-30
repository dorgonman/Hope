// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "HorizonCore.h"

#include "Slate.h"


class FHorizonCoreModule : public IHorizonCoreModule
{
public:
    virtual void StartupModule() override
    {
        // Load for cooker reference
       // LoadObject<UObject>(NULL, TEXT("/Game/UI/Menu/LoadingScreen.LoadingScreen"));

    }

    virtual bool IsGameModule() const override
    {
        return true;
    }

    virtual void DumpModuleInfo() override
    {
      
    }
};

IMPLEMENT_GAME_MODULE(FHorizonCoreModule, HorizonCore);
