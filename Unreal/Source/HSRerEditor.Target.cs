// Adam

using UnrealBuildTool;
using System.Collections.Generic;

public class HSRerEditorTarget : TargetRules
{
	public HSRerEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "HSRer" } );
	}
}
