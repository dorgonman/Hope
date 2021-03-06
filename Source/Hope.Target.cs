// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class HopeTarget : TargetRules
{
	public HopeTarget(TargetInfo Target)
	{
		Type = TargetType.Game;
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
        //OutExtraModuleNames.AddRange(new string[] { "Hope", "HorizonCore" });
        OutExtraModuleNames.AddRange(new string[] { "Hope"});
	}
}
