// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#include "Engine.h"

#include "MyTestEditorPluginObject.h"

#include "MyEditorPlugin.h"
UMyTestEditorPluginObject::UMyTestEditorPluginObject(const class FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()){

}
void UMyTestEditorPluginObject::test(){
    UE_LOG(LogMyEditorPlugin, Log, TEXT("test"));
}