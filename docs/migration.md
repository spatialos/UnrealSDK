# Unreal SDK:
# Upgrading to SpatialOS 13.0
# Migrating to the Unreal SDK 1.0.0

GitHub repository: [github.com/spatialos/UnrealSDK](https://github.com/spatialos/UnrealSDK)

**NOTE**: The steps below tell you how to migrate from an earlier version of SpatialOS and the Unreal SDK (before SpatialOS version 13).
If you are installing SpatialOS and the Unreal SDK for the first time, see: [Introduction to the Unreal SDK](introduction.md).

SpatialOS 13.0 splits SpatialOS and the Unreal SDK to make SpatialOS available as a separate product to the Unreal SDK.
At the time of initial release, the functionality of SpatialOS 13.0 and the Unreal SDK 1.0.0 is the same as the combined SpatialOS and Unreal SDK 12.2.1. Subsequent patch releases may make the functionality of the versions slightly different.
If you want to use the Unreal SDK 1.0.0, you need to upgrade your SpatialOS version to 13.0 and
migrate your Unreal SDK version to 1.0.0.

Follow the steps below for every SpatialOS Unreal project you want to upgrade and migrate.

## Quick guide
1. Run `spatial clean`.
1. Clone the [SpatialOS Unreal SDK GitHub repository](https://github.com/spatialos/UnrealSDK).
1. From the cloned repository, move the `Game` directory into your project’s Unreal worker directory (this is usually `<root>/workers/unreal`).
	If you are asked whether to merge or replace the `Game` folder, select merge, otherwise you will delete files that your game depends upon.
1. Still in the Unreal worker directory, edit the `spatialos.UnrealClient.worker.json` file to remove `"generated_build_scripts_type": "unreal"` completely
and to replace `"Game/Intermediate/Improbable/spatialos.unreal.client.build.json"` with `"Game/Source/SpatialOS/spatialos.unreal.client.build.json".` Be sure to remove the comma after `.json"`.
1. Edit the `spatialos.UnrealWorker.worker.json` file to remove `"generated_build_scripts_type": "unreal"` completely
and to replace `"Game/Intermediate/Improbable/spatialos.unreal.worker.build.json"` with `"Game/Source/SpatialOS/spatialos.unreal.worker.build.json".` Be sure to remove the comma after `.json"`.
1. In `<root>\workers\unreal\Game\Intermediate\Improbable` delete the `spatialos_worker_packages.json` file.
1. In `Game/<yourgame>.uproject` replace all instances of `spatial invoke unreal` with
`Binaries\\ThirdParty\\Improbable\\Programs\\unreal_packager`.
1. Edit the `spatialos.json` file in two places so that `"version" is “13.0.0”`.
1. Run `spatial clean` (again).
1. Run `spatial worker build`.
1. In your project's Unreal worker directory (for example, `workers/unreal`), edit the version control system (VCS) ignore file as below:
    * Change the line `**/Binaries/` to `**/Binaries/*`
    * Add the line `!Game/Binaries/ThirdParty/`
    * Delete the line `Game/Source/SpatialOS/*`

**Note:** In all our starter projects downloaded before 2018-05-15 the VCS ignore files are not set as above, so if your project is based on any of these projects, you need to edit the VCS ignore files as described in the final step.

## Detailed guide

### 1. Clean up your existing project
1. Open a terminal window and `cd` to the root directory of your project.
2. Run `spatial clean`.
Note: It’s very important you start by running `spatial clean`. If you don’t, files won’t be cleaned up properly and
may cause issues with the new version.

### 2. Clone or download the Unreal SDK 1.0.0.
Get the Unreal SDK by cloning the [SpatialOS Unreal SDK GitHub repository](https://github.com/spatialos/UnrealSDK).
Either follow the **Clone or download** instructions on the web page or clone using the command line. (See the [git-scm](https://git-scm.com/book/en/v2/Git-Basics-Getting-a-Git-Repository) website for guidance on setting up and using command-line git.)


For command-line git, in a terminal window run:
`git clone github.com/spatialos/UnrealSDK`

### 3. Upgrade your Unreal project

1. From the cloned repository, copy the contents of the `Game` directory into the directory which contains
your Unreal project’s workers. (It is the directory which contains the `spatialos_worker_packages.json` file.)
For example: `~/mySpatialOSgame/workers/unreal`
2. In the same directory, edit the `spatialos.UnrealClient.worker.json` file to remove  `"generated_build_scripts_type": "unreal"`
completely and to replace `"spatialos.unreal.client.build.json"` with `"Game/Source/SpatialOS/spatialos.unreal.client.build.json"`. Make sure there is no comma after `.json"`.

This part of the file should now look like this:
```
"build": {
   "tasks_filename": "Game/Source/SpatialOS/spatialos.unreal.client.build.json"
  },
```


3. In the same directory, edit the `spatialos.UnrealWorker.worker.json` file to remove the `"generated_build_scripts_type": "unreal"`
completely and to replace `"spatialos.unreal.client.build.json"` with `"Game/Source/SpatialOS/spatialos.unreal.client.build.json".` Make sure there is no comma after `.json"`.

This part of the file should now look like this:
```
"build": {
    "tasks_filename": "Game/Source/SpatialOS/spatialos.unreal.client.build.json"
  },
```

4. Delete `spatialos_worker_packages.json` as `spatial` no longer uses this file.

5. In `Game/<yourgame>.uproject` replace all instances of `spatial invoke unreal` with
`Binaries\\ThirdParty\\Improbable\\Programs\\unreal_packager`.

For example, the `PostBuildSteps` section of `Game/<yourgame.uproject>` should now look like this:
```
"PostBuildSteps":
    {
        "Win64": [
            "cd /D \"$(ProjectDir)\"",
            "Binaries\\ThirdParty\\Improbable\\Programs\\unreal_packager package --engineDir=\"$(EngineDir)\" --project=\"$(ProjectFile)\" --platform=\"$(TargetPlatform)\" --target=\"$(TargetType)\" --configuration=\"$(TargetConfiguration)\" -- -allmaps",
            "exit /B %ERRORLEVEL%"
        ],
        "Linux": [
            "cd \"$(ProjectDir)\"",
            "Binaries\\ThirdParty\\Improbable\\Programs\\unreal_packager package --engineDir=\"$(EngineDir)\" --project=\"$(ProjectFile)\" --platform=\"$(TargetPlatform)\" --target=\"$(TargetType)\" --configuration=\"$(TargetConfiguration)\" -- -allmaps",
            "exit /B %ERRORLEVEL%"
        ]
    }
}
```

6. Navigate two directories up to find the `spatialos.json` file.
Edit the `spatialos.json` file so that the `"version"` is `“13.0.0”` and save the file. Note that there are two places
to edit the version.

The file should now look similar to this:

```
{
    "name": "mySpatialOSgame",
    "project_version": "1.0.0",
    "sdk_version": "13.0.0",
    "dependencies": [
    	{"name": "standard_library", "version": "13.0.0"}
    ]
}
```

7. In the root directory of your project, run `spatial clean` (again).

### 3. Update the version control ignore file
Make sure your version control system (VCS) is set to **stop ignoring** the Unreal SDK directories you have copied, specifically the directories under `Game/Binaries/ThirdParty/Improbable` and `Source/SpatialOS` which are ignored by default. 


1. Locate the VCS ignore file in your project’s Unreal worker directory.
* For example, in the Unreal Starter project on GitHub, the VCS ignore file to edit is in the `workers/unreal` directory [github.com/spatialos/UnrealStarterProject/blob/master/workers/unreal/.gitignore](https://github.com/spatialos/UnrealStarterProject/blob/master/workers/unreal/.gitignore)

2. Edit the ignore file as below:
    * Change the line `**/Binaries/` to `**/Binaries/*`
    * Add the line `!Game/Binaries/ThirdParty/`
    * Delete the line `Game/Source/SpatialOS/*`

You need to do this for every project you migrate.

**Note:** In all our starter projects (including Unreal Starter) downloaded before 2018-05-15 the version control ignore files are not set as above, so if your project is based on any of these starter projects, you need to edit the VCS ignore files.


### 4. Check it worked
In the root directory of your project, check that the upgrade and migration worked by running:
`spatial worker build`.


It’s worked when you see `'spatial build UnrealWorker UnrealClient' succeeded` (or `'spatial.exe build UnrealWorker UnrealClient' succeeded`).
