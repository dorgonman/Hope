// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MyTestDeveloperPluginObject.generated.h"


/**
 * Example UStruct declared in a plugin module
 */
USTRUCT()
struct MYDEVELOPERPLUGIN_API FMyTestDeveloperPluginStruct
{
	GENERATED_USTRUCT_BODY()
 
	UPROPERTY()
	FString TestString;
};
 

/**
 * Example of declaring a UObject in a plugin module
 */
UCLASS()
class MYDEVELOPERPLUGIN_API UMyTestDeveloperPluginObject : public UObject
{
public:
    GENERATED_UCLASS_BODY()

public:
    void test();


private:
    
	UPROPERTY()
	FMyTestDeveloperPluginStruct MyStruct;

};


