// Copyright 1998-2011 Epic Games, Inc. All Rights Reserved.
using UnrealBuildTool;
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
public class Boost : ModuleRules
{
	public Boost(TargetInfo Target)
	{
		Type = ModuleType.External;

		bool isLibrarySupported = false;

		if(tryInitWindows(Target)){
			isLibrarySupported = true;
		}
            
        if(tryInitMac(Target)){
			isLibrarySupported = true;
		}

		if(tryInitAndroid(Target)){
			isLibrarySupported = true;
		}

        if (isLibrarySupported)
        {
            PublicIncludePaths.Add(ModuleIncludePath);

        }   
        Definitions.Add(string.Format("WITH_BOOST_BINDING={0}", isLibrarySupported ? 1 : 0));
	}


    bool tryInitWindows(TargetInfo Target)
    {
		bool bRet = false;

        if (Target.Platform == UnrealTargetPlatform.Win64 ||
            Target.Platform == UnrealTargetPlatform.Win32)
        {


           // if (WindowsPlatform.Compiler == WindowsCompiler.VisualStudio2013)
            {
                if (Target.Platform == UnrealTargetPlatform.Win64)
                {
                    PublicLibraryPaths.Add(LibrariesWin64Path);
                }
                //if (Target.Platform == UnrealTargetPlatform.Win32)
                {
                    PublicLibraryPaths.Add(LibrariesWin32Path);
                }
                
                //if (Target.Configuration == UnrealTargetConfiguration.Debug)
                {
                    //AddPublicAdditionalLibrary("libboost_system-vc120-mt-1_57.lib");
                    //PublicAdditionalLibraries.Add("libboost_exception-vc120-mt-1_57.lib");
                    PublicAdditionalLibraries.Add("libboost_system-vc120-mt-1_57.lib");

                    
                }
                //disable auto linking
                Definitions.Add("BOOST_ALL_NO_LIB");
                //Definitions.Add("BOOST_LIB_DIAGNOSTIC");
               // Definitions.Add("BOOST_NO_EXCEPTIONS");
                 
                
                bRet = true;
            }
        }
		





		return bRet;
	}


	bool tryInitMac(TargetInfo Target){
		bool bRet = false;
		if (Target.Platform == UnrealTargetPlatform.Mac)
		{
			//AddPublicLibraryPath(LibrariesMacPath);
			PublicLibraryPaths.Add(LibrariesMacPath);
			//PublicLibraryPaths.Add("/Users/apple/workspace/UnrealGameProjects/Hope1/Source/ThirdParty/Boost/boost_1_57_0/stage/lib/Mac/x86_64/");
			//if (Target.Configuration == UnrealTargetConfiguration.Debug)
			//{
				//PublicAdditionalLibraries.Add("boost_system-vc120-mt-gd-1_57.lib");
                //PublicDelayLoadDLLs.Add("boost_system-vc120-mt-gd-1_57.dll");
			//}
			//else
			{
				//AddPublicAdditionalLibrary("libboost_system.a");
				string libBoostSystem = LibrariesMacPath + "/libboost_system.a";
                PublicAdditionalLibraries.Add(libBoostSystem);
                //PublicDelayLoadDLLs.Add("boost_system-vc120-mt-1_57.dll");
			}

			bRet = true;
			
		}

		return bRet;
	}


	bool tryInitAndroid(TargetInfo Target){
		bool bRet = false;
		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			//AddPublicLibraryPath(LibrariesMacPath);
            PublicLibraryPaths.Add(LibrariesAndroidPath);
			//PublicLibraryPaths.Add("/Users/apple/workspace/UnrealGameProjects/Hope1/Source/ThirdParty/Boost/boost_1_57_0/stage/lib/Mac/x86_64/");
			//if (Target.Configuration == UnrealTargetConfiguration.Debug)
			//{
				//PublicAdditionalLibraries.Add("boost_system-vc120-mt-gd-1_57.lib");
                //PublicDelayLoadDLLs.Add("boost_system-vc120-mt-gd-1_57.dll");
			//}
			//else
			{
				//AddPublicAdditionalLibrary("libboost_system.a");
				string libBoostSystem = LibrariesAndroidPath + "/libboost_system-gcc-mt-1_57.a";
                PublicAdditionalLibraries.Add(libBoostSystem);
                //PublicDelayLoadDLLs.Add("boost_system-vc120-mt-1_57.dll");
			}

			bRet = true;
			
		}

		return bRet;
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
    private string ModuleIncludePath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleFullPath, "boost_1_57_0")); }
    }	
    private string LibrariesWin64Path
	{
        get { return Path.GetFullPath(Path.Combine(ModuleIncludePath, "stage", "lib", "Win64", 
        										   "VS" + WindowsPlatform.GetVisualStudioCompilerVersionName(), 
                                                   //"DynamicLinkLibrary"
                                                   "StaticLibrary"
                                                   )); }
    }
    private string LibrariesWin32Path
    {
        get
        {
            return Path.GetFullPath(Path.Combine(ModuleIncludePath, "stage", "lib", "Win32",
                                                 "VS" + WindowsPlatform.GetVisualStudioCompilerVersionName(),
                                                //"DynamicLinkLibrary"
                                                 "StaticLibrary"
                                                 ));
        }
    }		
    private string LibrariesMacPath
	{
        get { return Path.GetFullPath(Path.Combine(ModuleIncludePath, "stage", "lib", "Mac", "x86_64"//, 
                                                   //"DynamicLinkLibrary"
                                                  // "StaticLibrary"
                                                   )); }
    }	

    private string LibrariesAndroidPath
	{
        get { return Path.GetFullPath(Path.Combine(ModuleIncludePath, "stage", "lib", "Android", "arm-linux-androideabi"//, 
                                                   //"DynamicLinkLibrary"
                                                  // "StaticLibrary"
                                                   )); }
    }				
}

