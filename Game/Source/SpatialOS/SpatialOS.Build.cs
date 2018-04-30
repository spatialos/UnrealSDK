// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

using System;
using System.ComponentModel;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;
using UnrealBuildTool;

public class SpatialOS : ModuleRules
{
#if !WITH_FORWARDED_MODULE_RULES_CTOR
    // Backwards compatibility with Unreal 4.15
    public SpatialOS(TargetInfo Target)
#else
    // Unreal 4.16+
    public SpatialOS(ReadOnlyTargetRules Target) : base(Target)
#endif
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        bFasterWithoutUnity = true;

        PublicIncludePaths.AddRange(
            new string[]
            {
                "SpatialOS/Public",
                "SpatialOS/Public/WorkerSdk",
                "SpatialOS/Generated/Usr",
                "SpatialOS/Generated/Std",
                "SpatialOS/Generated/UClasses",
            });

        PrivateIncludePaths.AddRange( new string[] { "SpatialOS/Private" });

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "Projects",
                "CoreUObject",
                "Engine"
            });

        var CoreSdkLibraryDir = Path.GetFullPath(Path.Combine(ModuleDirectory, "..", "..", "Binaries", "ThirdParty", "Improbable", Target.Platform.ToString()));
        string CoreSdkShared;

        if (Target.Platform == UnrealTargetPlatform.Win32 || Target.Platform == UnrealTargetPlatform.Win64)
        {
            CoreSdkShared = Path.Combine(CoreSdkLibraryDir, "CoreSdkDll.dll");
            PublicAdditionalLibraries.AddRange(new[] { Path.Combine(CoreSdkLibraryDir, "CoreSdkDll.lib") });
        }
        else
        {
            CoreSdkShared = Path.Combine(CoreSdkLibraryDir, "libCoreSdkDll.so");
            PublicAdditionalLibraries.AddRange(new[] { CoreSdkShared });
        }

        RuntimeDependencies.Add(CoreSdkShared, StagedFileType.NonUFS);

        PublicLibraryPaths.Add(CoreSdkLibraryDir);
        PublicDelayLoadDLLs.Add("CoreSdkDll.dll");

        // Point generated code to the correct API spec.
        Definitions.Add("IMPROBABLE_DLL_API=SPATIALOS_API");
    }
}
