// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class HopeEditorTarget : TargetRules
{
	public HopeEditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
        //bDebugBuildsActuallyUseDebugCRT = false;
	}

	//
	// TargetRules interface.
	//

	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{

        OutExtraModuleNames.AddRange(new string[] { "Hope"});
        // OutExtraModuleNames.AddRange(new string[] { "Hope", "HorizonCore" });
	}
}
