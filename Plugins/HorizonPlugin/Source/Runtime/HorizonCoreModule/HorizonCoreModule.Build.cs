// Copyright 1998-2011 Epic Games, Inc. All Rights Reserved.
using UnrealBuildTool;

using System;
using System.IO;
/*public enum UnrealTargetPlatform
	{
		Unknown,
		Win32,
		Win64,
		Mac,
		XboxOne,
		PS4,
		IOS,
		Android,
		WinRT,
		WinRT_ARM,
		HTML5,
        Linux,
	}
*/
public class HorizonCoreModule : ModuleRules
{

	public HorizonCoreModule(TargetInfo Target)
	{
		Type = ModuleType.External;

		checkExternalLibPath();

		bool isLibrarySupported = false;

		if(tryInitWin64(Target)){
			isLibrarySupported = true;
		}

        if (tryInitWin32(Target))
        {
            isLibrarySupported = true;
        }
            
        if (isLibrarySupported)
        {
            PublicIncludePaths.Add(ModuleLibPublicIncludePath);

        }   

        Definitions.Add(string.Format("WITH_HORIZON_CORE_BINDING={0}", isLibrarySupported ? 1 : 0));
	}

	void checkExternalLibPath(){

        if (String.IsNullOrEmpty(ModuleLibRootPath))
        {
            System.Diagnostics.Debug.Assert(false, "checkExternalLibPath failed: Could not find " + ModuleEnvName + " in System Environment");
        }else{
        	System.Diagnostics.Debug.WriteLine("Find " + ModuleEnvName +  " version:");
        }

        //boost/version.hpp
        //#define BOOST_LIB_VERSION "1_59"
	}
    
	bool tryInitWin64(TargetInfo Target){
		bool bRet = false;
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{

			if (WindowsPlatform.Compiler == WindowsCompiler.VisualStudio2013)
			{
                string LibSearchPath =
                           Path.GetFullPath(Path.Combine(ModuleLibRootPath,
                                           "HorizonCore", "cpp", "libs", "win64", "vs2013", "Release"));
                PublicLibraryPaths.Add(LibSearchPath);
                string LibFilePath = Path.Combine(LibSearchPath, "HorizonCoreStatic.lib");
                PublicAdditionalLibraries.Add(LibFilePath); 
				bRet = true;
			}
		}

		return bRet;
	}

    bool tryInitWin32(TargetInfo Target)
    {
        bool bRet = false;
        if (Target.Platform == UnrealTargetPlatform.Win32)
        {

            if (WindowsPlatform.Compiler == WindowsCompiler.VisualStudio2013)
            {
                string LibSearchPath = 
                    Path.GetFullPath(Path.Combine(ModuleLibRootPath,
                                    "HorizonCore", "cpp", "libs", "win32", "vs2013", "Release"));
                PublicLibraryPaths.Add(LibSearchPath);
                string LibFilePath = Path.Combine(LibSearchPath, "HorizonCoreStatic.lib");
                PublicAdditionalLibraries.Add(LibFilePath);
                bRet = true;
            }
        }

        return bRet;
    }


	private string ModuleFilePath
    {
        get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
    }

    //==================Begin external library root path==============================
    private string ModuleEnvName
    {
        get { return "HORIZON_ENGINE_ROOT"; }
    }
    private string ModuleLibRootPath
    {
        get { return Path.GetFullPath(Environment.GetEnvironmentVariable(ModuleEnvName)); }
    }

    private string ModuleLibPublicIncludePath
    {
        
        get { return Path.GetFullPath(Path.Combine(ModuleLibRootPath, "HorizonCore", "cpp", "Public")); }
    }
    //==================End external library root path==============================
}

