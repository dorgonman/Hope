//using UnrealBuildTool;
using System;
using System.IO;
namespace UnrealBuildTool.Rules
{
	public class HorizonPlugin : ModuleRules
	{
        private void showDebugInfo(TargetInfo Target)
        {
            //Type is one of three values, Developer, 
            //Runtime or Editor. Editor is loaded at editor load time, 
            //Runtime is loaded in all contexts, 
            //and Developer is loaded at any time where you are loading a Development build and never for Shipping builds. 
            //PublicIncludePaths.AddRange(new string[] { "Runtime/HorizonPlugin/Public" });
            //PrivateIncludePaths.AddRange(new string[] { "Runtime/HorizonPlugin/Private" });
            // string BoostRootPath = GetEnvironmentVariable("BOOST_ROOT");
            // System.Diagnostics.Debug.WriteLine("HorizonPlugin=======================================================aaaaa");   
            // if (!String.IsNullOrEmpty(BoostRootPath))

            // PrivateDependencyModuleNames.AddRange(new string[] { "Boost" });
            //DynamicallyLoadedModuleNames.Add("VulkanRHI");
            System.Diagnostics.Debug.WriteLine("========================Start Compile HorizonPlugin=======================");
            System.Diagnostics.Debug.WriteLine("Target.Platform:" + Target.Platform);
            System.Diagnostics.Debug.WriteLine("Target.Architecture:" + Target.Architecture); 
            System.Diagnostics.Debug.WriteLine("Target.Configuration:" + Target.Configuration);
            System.Diagnostics.Debug.WriteLine("Target.Type:" + Target.Type);
            System.Diagnostics.Debug.WriteLine("Target.IsCooked:" + Target.IsCooked);
            System.Diagnostics.Debug.WriteLine("Target.bIsMonolithic:" + Target.bIsMonolithic);
            System.Diagnostics.Debug.WriteLine("this.PublicIncludePaths:" + string.Join(",", this.PublicIncludePaths.ToArray()));
            //InitBoost();
            string[] args = Environment.GetCommandLineArgs();
            foreach (string arg in args)
            {
                System.Diagnostics.Debug.WriteLine("parameter:" + arg);
            }
        
        }
      

		public HorizonPlugin (TargetInfo Target)
		{
          

            PublicIncludePaths.AddRange(new string[] { "Public" });
            PrivateIncludePaths.AddRange(new string[] { "Private" });
			PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "Slate", "SlateCore", "Http" });
			PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		    DynamicallyLoadedModuleNames.AddRange(new string[] { /* ... add any modules that your module loads dynamically here ... */ });
            PrivateDependencyModuleNames.AddRange(new string[] {"HorizonCoreModule", "BoostModule" });

            //bFasterWithoutUnity = true;
            // Enable RTTI (prop. of superclass ModuleRules defined in UnrealEngine/Engine/Source/Programs/UnrealBuildTool/System/RulesCompiler.cs )
            bUseRTTI = true;
            // this seems be ignored on a mac, check UnrealEngine/Engine/Source/Programs/UnrealBuildTool/Mac/MacToolChain.cs
            // Enable C++ Exceptions for this module
            bEnableExceptions = true;
            // eventually needed as well
            UEBuildConfiguration.bForceEnableExceptions = true;
            Definitions.Add("BOOST_ALL_NO_LIB"); //disable auto link
		}

        private string ModulePath
        {
            get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
        }

       


	}
}