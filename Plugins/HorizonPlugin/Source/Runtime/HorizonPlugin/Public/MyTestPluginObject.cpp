// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#include "Engine.h"

#include "MyTestPluginObject.h"

#include "MyPlugin.h"
UMyTestPluginObject::UMyTestPluginObject(const class FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()){

}
void UMyTestPluginObject::test(){
    UE_LOG(LogMyPlugin, Log, TEXT("test"));
}