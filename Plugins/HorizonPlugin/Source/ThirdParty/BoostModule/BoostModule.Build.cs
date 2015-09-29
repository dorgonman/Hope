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
public class BoostModule : ModuleRules
{

	public BoostModule(TargetInfo Target)
	{
		Type = ModuleType.External;

		checkExternalLibPath();
        parseBoostVersion(Target);

        bool isLibrarySupported = false;

        //if (Directory.Exists(LibSearchPath))
        string LibSearchPath = GetLibSearchPath(Target);
        if (!String.IsNullOrEmpty(LibSearchPath))
        {

            PublicLibraryPaths.Add(LibSearchPath);
            Definitions.Add("BOOST_ALL_NO_LIB"); //disable auto link
            foreach (string boostLib in BoostLibraryList)
            {
                addBoostLibrary(LibSearchPath, boostLib);
            }
            isLibrarySupported = true;
        }
        else {
            System.Diagnostics.Debug.Assert(false, "xxxx");
        }


        if (isLibrarySupported)
        {
            PublicIncludePaths.Add(ModuleLibPublicIncludePath);

        }
        Definitions.Add(string.Format("WITH_BOOST_BINDING={0}", isLibrarySupported ? 1 : 0));
	}

	void checkExternalLibPath(){
        if (String.IsNullOrEmpty(ModuleLibRootPath))
        //if (Directory.Exists(ModuleLibRootPath))
        {
            System.Diagnostics.Debug.Assert(false, "checkExternalLibPath failed: Could not find " + ModuleEnvName + " in System Environment");
        }
	}

	bool tryInitWin64(TargetInfo Target){
		bool bRet = false;
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			if (WindowsPlatform.Compiler == WindowsCompiler.VisualStudio2013)
			{
	
	          
            
              
				bRet = true;
			}
		}

		return bRet;
	}

    void addBoostLibrary(string libSearchPath, string boostSystemName)
    {
        string boostVer = "-" + BoostVersion;
        string gd = "";// -gd, should not use debug version
        string vc = "-vc120";
        string mt = "-mt";

        string libBoostFileName = "libboost_" + boostSystemName + vc + mt + gd + boostVer + ".lib";
        string libBoostFilePath = Path.GetFullPath(Path.Combine(libSearchPath, libBoostFileName));
        PublicAdditionalLibraries.Add(libBoostFilePath);
    }

    void parseBoostVersion(TargetInfo Target)
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
                BoostVersion = tmpVersion.Replace("\"", "");
                Console.WriteLine("BoostModule Root Path:" + ModuleLibRootPath);
                Console.WriteLine("BoostModule Library Search Path:" + GetLibSearchPath(Target));
                Console.WriteLine("BoostModule library Version:" + BoostVersion);
                break;
            }
        }
    
    }

    //=================Begin Library search path==========================

    private string GetLibSearchPath(TargetInfo Target)
    {

        string boostLibrayDir = Environment.GetEnvironmentVariable("BOOST_LIBRARYDIR"); 
        if (!String.IsNullOrEmpty(boostLibrayDir))
        {
            Console.WriteLine("LibSearchPath use system environment BOOST_LIBRARYDIR:" + boostLibrayDir);
            return boostLibrayDir;
        }
        else
        {
            //
            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                if (WindowsPlatform.Compiler == WindowsCompiler.VisualStudio2013)
                {
                    return getLibSearchPath64("win64", "vs2013");
                }
            }
        }
        return "";
    }

    private string getLibSearchPath64(string platform, string visualStudioVer)
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
    private string BoostVersion;

   

    //==================Begin external library root path==============================
    private string ModuleEnvName
    {
        get { return "BOOST_ROOT"; }
    }
    private string ModuleLibRootPath
    {
        get { return Environment.GetEnvironmentVariable(ModuleEnvName); }
    }	

    private string ModuleLibPublicIncludePath
    {
        get { return ModuleLibRootPath; }
    }
    //==================End external library root path==============================
	    
}

