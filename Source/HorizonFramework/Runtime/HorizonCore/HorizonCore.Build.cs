// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.IO;
public class HorizonCore : ModuleRules
{
	public HorizonCore(TargetInfo Target)
	{
        PublicIncludePaths.Add(ModuleIncludePublicPath);
        PrivateIncludePaths.Add(ModuleIncludePrivatePath);
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Paper2D" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });


       // PublicDependencyModuleNames.AddRange(new string[] { "UMG", "Slate", "SlateCore", "MovieSceneCore", "UnrealEd" });
        PublicDependencyModuleNames.AddRange(new string[] { "UMG", "Slate", "SlateCore", "MovieSceneCore" });

        PrivateDependencyModuleNames.AddRange(new string[] { "Boost" });
	}

    private string ModulePath
    {
        get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
    }
    private string ModuleFullPath
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, ".")); }
        //get { return Path.GetFullPath(Path.Combine(UEBuildConfiguration.UEThirdPartySourceDirectory, "Boost")); }
    }	
    private string ModuleIncludePublicPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleFullPath, "Public")); }
    }	

    private string ModuleIncludePrivatePath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleFullPath, "Private")); }
    }   

}
