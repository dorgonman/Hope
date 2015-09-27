// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MyTestEditorPluginObject.generated.h"


/**
 * Example UStruct declared in a plugin module
 */
USTRUCT()
struct MYEDITORPLUGIN_API FMyTestEditorPluginStruct
{
	GENERATED_USTRUCT_BODY()
 
	UPROPERTY()
	FString TestString;
};
 

/**
 * Example of declaring a UObject in a plugin module
 */
UCLASS()
class MYEDITORPLUGIN_API UMyTestEditorPluginObject : public UObject
{
public:
    GENERATED_UCLASS_BODY()

public:
    void test();


private:
    
	UPROPERTY()
	FMyTestEditorPluginStruct MyStruct;

};


