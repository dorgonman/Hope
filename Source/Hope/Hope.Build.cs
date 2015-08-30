// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Hope : ModuleRules
{
	public Hope(TargetInfo Target)
	{
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Paper2D" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });


       // PublicDependencyModuleNames.AddRange(new string[] { "UMG", "Slate", "SlateCore", "MovieSceneCore", "UnrealEd" });
        PublicDependencyModuleNames.AddRange(new string[] { "UMG", "Slate", "SlateCore", "MovieSceneCore" });
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
        Definitions.Add("PERF_DETAILED_PER_CLASS_GC_STATS");
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
		// {
		//		if (UEBuildConfiguration.bCompileSteamOSS == true)
		//		{
		//			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//		}
		// }

        PrivateDependencyModuleNames.AddRange(new string[] { "Boost", "HorizonCore" });
	}
}
