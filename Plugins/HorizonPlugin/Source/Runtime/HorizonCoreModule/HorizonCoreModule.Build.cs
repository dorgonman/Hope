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
        parseVersion(Target);

        bool isLibrarySupported = false;

        //if (Directory.Exists(LibSearchPath))
        string LibSearchPath = GetLibSearchPath(Target);
        if (!String.IsNullOrEmpty(LibSearchPath))
        {

            PublicLibraryPaths.Add(LibSearchPath);

            string LibFilePath = Path.Combine(LibSearchPath, "HorizonCoreStatic.lib");
            PublicAdditionalLibraries.Add(LibFilePath);
            isLibrarySupported = true;
        }
        else
        {
            System.Diagnostics.Debug.Assert(false, "Could not find library search path: " + LibSearchPath);
        }


        if (isLibrarySupported)
        {
            PublicIncludePaths.Add(ModuleLibPublicIncludePath);

        }


        Definitions.Add(string.Format("WITH_HORIZON_CORE_BINDING={0}", isLibrarySupported ? 1 : 0));
	}

    void checkExternalLibPath()
    {
        if (String.IsNullOrEmpty(ModuleLibRootPath))
        {
            System.Diagnostics.Debug.Assert(false, "checkExternalLibPath failed: Could not find " + ModuleLibRootEnvName + " in System Environment");
        }
    }

    void parseVersion(TargetInfo Target)
    {
    
        string verionFile = Path.GetFullPath(Path.Combine(ModuleLibRootPath, "cpp", "Public", "HorizonVersions.h"));
        System.IO.StreamReader file = new System.IO.StreamReader(verionFile);
        string line;
        while ((line = file.ReadLine()) != null)
        {
            if (line.Contains("#define HORIZON_VERSION_NAME"))
            {
                string[] words = line.Split(' ');
                string tmpVersion = words[2].ToString();
                LibraryVersion = tmpVersion.Replace("\"", "");
                Console.WriteLine("HorizonCoreModule Root Path:" + ModuleLibRootPath);
                Console.WriteLine("HorizonCoreModule Library Search Path:" + GetLibSearchPath(Target));
                Console.WriteLine("HorizonCoreModule library Version:" + LibraryVersion);
                break;
            }
        }

    }
	
    //=================Begin win32 extra flag==========================
    private string WindowsVSToolSet;

    //=================End win32 extra flag==========================

    //=================Begin Library search path==========================

    private string GetLibSearchPath(TargetInfo Target)
    {

        string userDefinedLibraryPath = Environment.GetEnvironmentVariable("HORIZONCORE_LIBRARYDIR");
        if (!String.IsNullOrEmpty(userDefinedLibraryPath))
        {
            Console.WriteLine("LibSearchPath use system environment HORIZONCORE_LIBRARYDIR:" + userDefinedLibraryPath);
            return userDefinedLibraryPath;
        }
        else
        {
            //
            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                if (WindowsPlatform.Compiler == WindowsCompiler.VisualStudio2015)
                {
                    WindowsVSToolSet = "vc140";
                    return getVisualStudioLibSearchPath("win64", "vs2015");
                }
                else if (WindowsPlatform.Compiler == WindowsCompiler.VisualStudio2013)
                {
                    WindowsVSToolSet = "vc120";
                    return getVisualStudioLibSearchPath("win64", "vs2013");
                }
            }
            else if (Target.Platform == UnrealTargetPlatform.Win32)
            {
                if (WindowsPlatform.Compiler == WindowsCompiler.VisualStudio2015)
                {
                    WindowsVSToolSet = "vc140";
                    return getVisualStudioLibSearchPath("win32", "vs2015");
                }
                else if (WindowsPlatform.Compiler == WindowsCompiler.VisualStudio2013)
                {
                    WindowsVSToolSet = "vc120";
                    return getVisualStudioLibSearchPath("win32", "vs2013");
                }

            }
            else if (Target.Platform == UnrealTargetPlatform.Android)
            {

            }
        }
        return "";
    }

    private string getVisualStudioLibSearchPath(string platform, string visualStudioVer)
    {

        return Path.GetFullPath(Path.Combine(ModuleLibRootPath,
                        "cpp", "libs", platform, visualStudioVer, "Release"));

    }
    //=================End Library search path============================


	private string ModuleFilePath
    {
        get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
    }
    private string LibraryVersion;
    //==================Begin external library root path==============================
    private string ModuleLibRootEnvName
    {
        get { return "HORIZON_ENGINE_ROOT"; }
    }
    private string ModuleLibRootPath
    {
        get { return Path.Combine(Environment.GetEnvironmentVariable(ModuleLibRootEnvName), "HorizonCore"); }
    }

    private string ModuleLibPublicIncludePath
    {
        
        get { return Path.GetFullPath(Path.Combine(ModuleLibRootPath, "cpp", "Public")); }
    }
    //==================End external library root path==============================
}

