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
        public void InitHorizonEngine(TargetInfo Target)
        {
            //@TODO: This need to be kept in sync with RulesCompiler.cs for now
            bool bSupported = false;

            string HorizonEngineRoot = Environment.GetEnvironmentVariable("HORIZON_ENGINE_ROOT");
            if (!String.IsNullOrEmpty(HorizonEngineRoot))
            {
                bSupported = true;
                string horizonCoreIncludePath = HorizonEngineRoot + "/HorizonCore/cpp/Public/";
                PublicIncludePaths.Add(horizonCoreIncludePath);

               
                //C:\Users\dorgonman\Documents\workspace\HorizonEngine\HorizonCore\cpp\libs\win32\vs2013\Debug
                string horizonCoreLibPath = HorizonEngineRoot + "/HorizonCore/cpp/libs/win64/vs2013/Release/";
                PublicLibraryPaths.Add(horizonCoreLibPath);
                string LibrariesPath = Path.Combine(horizonCoreLibPath, "HorizonCoreStatic.lib");
                PublicAdditionalLibraries.Add(LibrariesPath); 
            }
            else
            {
                System.Diagnostics.Debug.Assert(false, "oops! Could not find HORIZON_ENGINE_ROOT in System Environment");
            }
           /* if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32))
            {
                bSupported = true;
            }

            bSupported = bSupported && UEBuildConfiguration.bCompileBox2D;

            if (bSupported)
            {
                AddThirdPartyPrivateStaticDependencies(Target, "Box2D");
            }*/

            // Box2D included define (required because pointer types may be in public exported structures)
            //Definitions.Add(string.Format("WITH_BOOST_BINDING={0}", isLibrarySupported ? 1 : 0));
           // Definitions.Add("_USRDLL");

            Definitions.Add(string.Format("WITH_HORIZON_CORE={0}", bSupported ? 1 : 0));
        }

        public void InitBoost(TargetInfo Target) {
            string BoostRoot = Environment.GetEnvironmentVariable("BOOST_ROOT");
            PublicIncludePaths.Add(BoostRoot);
            string LibPath = BoostRoot + "/stage/win64/vs2013/Release/";
            PublicLibraryPaths.Add(LibPath);
           /* LOCAL_WHOLE_STATIC_LIBRARIES += boost_chrono_static
            LOCAL_WHOLE_STATIC_LIBRARIES += boost_data_time_static
            LOCAL_WHOLE_STATIC_LIBRARIES += boost_system_static
            LOCAL_WHOLE_STATIC_LIBRARIES += boost_thread_static
            LOCAL_WHOLE_STATIC_LIBRARIES += boost_regex_static
            LOCAL_WHOLE_STATIC_LIBRARIES += boost_timer_static
            LOCAL_WHOLE_STATIC_LIBRARIES += boost_iostreams_static
            LOCAL_WHOLE_STATIC_LIBRARIES += boost_filesystem_static
            LOCAL_WHOLE_STATIC_LIBRARIES += boost_log_setup_static
            LOCAL_WHOLE_STATIC_LIBRARIES += boost_log_static*/
            string gd = "";
            PublicAdditionalLibraries.Add("libboost_system-vc120-mt-" + gd + "1_59.lib");
            PublicAdditionalLibraries.Add("libboost_thread-vc120-mt-" + gd + "1_59.lib");
            PublicAdditionalLibraries.Add("libboost_log_setup-vc120-mt-" + gd + "1_59.lib");
            PublicAdditionalLibraries.Add("libboost_log-vc120-mt-" + gd + "1_59.lib");
            PublicAdditionalLibraries.Add("libboost_iostreams-vc120-mt-" + gd + "1_59.lib");
            Definitions.Add("BOOST_ALL_NO_LIB");
        }
		public HorizonPlugin (TargetInfo Target)
		{
            //bFasterWithoutUnity = true;
            // Enable RTTI (prop. of superclass ModuleRules defined in UnrealEngine/Engine/Source/Programs/UnrealBuildTool/System/RulesCompiler.cs )
            bUseRTTI = true;
            // this seems be ignored on a mac, check UnrealEngine/Engine/Source/Programs/UnrealBuildTool/Mac/MacToolChain.cs
            // Enable C++ Exceptions for this module
            bEnableExceptions = true;
            // eventually needed as well
            UEBuildConfiguration.bForceEnableExceptions = true;
            //UEBuildConfiguration.bDebugBuildsActuallyUseDebugCRT = false;
            InitBoost(Target);
            InitHorizonEngine(Target);

            PublicIncludePaths.AddRange(new string[] { "Public" });
            PrivateIncludePaths.AddRange(new string[] { "Private" });
			PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "Slate", "SlateCore", "Http" });
			PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		    DynamicallyLoadedModuleNames.AddRange(new string[] { /* ... add any modules that your module loads dynamically here ... */ });
		}

        private string ModulePath
        {
            get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
        }

       


	}
}