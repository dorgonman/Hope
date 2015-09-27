namespace UnrealBuildTool.Rules
{
	public class HorizonDeveloperPlugin : ModuleRules
	{
		public HorizonDeveloperPlugin (TargetInfo Target)
		{
            //Type is one of three values, Developer, 
            //Runtime or Editor. Editor is loaded at editor load time, 
            //Runtime is loaded in all contexts, 
            //and Developer is loaded at any time where you are loading a Development build and never for Shipping builds. 
			PublicIncludePaths.AddRange(new string[] { "HorizonDeveloperPlugin/Public" });
			PrivateIncludePaths.AddRange(new string[] { "HorizonDeveloperPlugin/Private" });
			PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "Slate", "SlateCore", "Http" });
			PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
			DynamicallyLoadedModuleNames.AddRange(new string[] { /* ... add any modules that your module loads dynamically here ... */ });
		}
	}
}