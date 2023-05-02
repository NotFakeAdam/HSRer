// Adam

using UnrealBuildTool;
using System.Collections.Generic;

public class HSRerTarget : TargetRules
{
	public HSRerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "HSRer" } );
	}
}
