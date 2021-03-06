﻿// Copyright 1998-2011 Epic Games, Inc. All Rights Reserved.
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
public class BoostModule : ModuleRules
{

	public BoostModule(TargetInfo Target)
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
            Definitions.Add("BOOST_ALL_NO_LIB"); //disable auto link
            foreach (string boostLib in BoostLibraryList)
            {
                addBoostLibrary(Target, LibSearchPath, boostLib);
            }
            isLibrarySupported = true;
        }
        else {
            System.Diagnostics.Debug.Assert(false, "Could not find library search path: " + LibSearchPath);
        }


        if (isLibrarySupported)
        {
            PublicIncludePaths.Add(ModuleLibPublicIncludePath);

        }
        Definitions.Add(string.Format("WITH_BOOST_BINDING={0}", isLibrarySupported ? 1 : 0));

        //bFasterWithoutUnity = true;
        // Enable RTTI (prop. of superclass ModuleRules defined in UnrealEngine/Engine/Source/Programs/UnrealBuildTool/System/RulesCompiler.cs )
        bUseRTTI = true;
        // this seems be ignored on a mac, check UnrealEngine/Engine/Source/Programs/UnrealBuildTool/Mac/MacToolChain.cs
        // Enable C++ Exceptions for this module
        bEnableExceptions = true;
        // eventually needed as well
        UEBuildConfiguration.bForceEnableExceptions = true;

	}

	void checkExternalLibPath(){
        if (String.IsNullOrEmpty(ModuleLibRootPath))
        //if (Directory.Exists(ModuleLibRootPath))
        {
            System.Diagnostics.Debug.Assert(false, "checkExternalLibPath failed: Could not find " + ModuleLibRootEnvName + " in System Environment");
        }
	}

    void addBoostLibrary(TargetInfo Target, string libSearchPath, string boostSystemName)
    {
        if (Target.Platform == UnrealTargetPlatform.Win64 ||
            Target.Platform == UnrealTargetPlatform.Win32)
        {
            string boostVer = "-" + LibraryVersion;
            string gd = "";// -gd, should not use debug version
            string vc = "-" + WindowsVSToolSet;
            string mt = "-mt";

            string libBoostFileName = "libboost_" + boostSystemName + vc + mt + gd + boostVer + ".lib";
            string libBoostFilePath = Path.GetFullPath(Path.Combine(libSearchPath, libBoostFileName));
            PublicAdditionalLibraries.Add(libBoostFilePath);
        }
        else { 
        
        }
    }

    void parseVersion(TargetInfo Target)
    {
        string verionFile = Path.GetFullPath(Path.Combine(ModuleLibRootPath, "boost", "version.hpp"));
        System.IO.StreamReader file = new System.IO.StreamReader(verionFile);
        string line;
        while ((line = file.ReadLine()) != null)
        {
            if (line.Contains("#define BOOST_LIB_VERSION"))
            {
                string[] words = line.Split(' ');
                string tmpVersion = words[2].ToString();
                LibraryVersion = tmpVersion.Replace("\"", "");
                Console.WriteLine("BoostModule Root Path:" + ModuleLibRootPath);
                Console.WriteLine("BoostModule Library Search Path:" + GetLibSearchPath(Target));
                Console.WriteLine("BoostModule library Version:" + LibraryVersion);
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

        string userDefinedLibraryPath = Environment.GetEnvironmentVariable("BOOST_LIBRARYDIR");
        if (!String.IsNullOrEmpty(userDefinedLibraryPath))
        {
            Console.WriteLine("LibSearchPath use system environment BOOST_LIBRARYDIR:" + userDefinedLibraryPath);
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
                        "stage", platform, visualStudioVer, "Release"));

    }
    //=================End Library search path============================

    private readonly string[] BoostLibraryList = { 
                 "system", "thread", 
                 "log_setup", "log",
                 "iostreams"};

	private string ModuleFilePath
    {
        get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
    }
    private string LibraryVersion;

   

    //==================Begin external library root path==============================
    private string ModuleLibRootEnvName
    {
        get { return "BOOST_ROOT"; }
    }
    private string ModuleLibRootPath
    {
        get { return Environment.GetEnvironmentVariable(ModuleLibRootEnvName); }
    }	

    private string ModuleLibPublicIncludePath
    {
        get { return ModuleLibRootPath; }
    }
    //==================End external library root path==============================
	    
}

