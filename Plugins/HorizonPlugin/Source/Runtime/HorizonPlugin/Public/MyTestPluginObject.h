// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MyTestPluginObject.generated.h"

//https://docs.unrealengine.com/latest/INT/Programming/Modules/API/index.html
/**
 * Example UStruct declared in a plugin module
 */
USTRUCT()
struct MYPLUGIN_API FMyTestPluginStruct
{
	GENERATED_USTRUCT_BODY()
 
	UPROPERTY()
	FString TestString;
};
 

/**
 * Example of declaring a UObject in a plugin module
 */
UCLASS()
class MYPLUGIN_API UMyTestPluginObject : public UObject
{
public:
    GENERATED_UCLASS_BODY()

public:
    void test();


private:
    
	UPROPERTY()
	FMyTestPluginStruct MyStruct;

};


