// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#include "Engine.h"

#include "MyTestDeveloperPluginObject.h"

#include "MyDeveloperPlugin.h"
UMyTestDeveloperPluginObject::UMyTestDeveloperPluginObject(const class FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()){

}
void UMyTestDeveloperPluginObject::test(){
    UE_LOG(LogMyDeveloperPlugin, Log, TEXT("test"));
}