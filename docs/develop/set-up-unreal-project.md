# Setting up a project

## Prerequisites

* **You've gone through the SDK setup guide** for [Windows](../get-started/setup/win.md) and have
    everything installed.
* **You have a project.** You can use one of the examples at the [SpatialOS GitHub repository](https://github.com/spatialos).

## 1. Configure project name

Make sure your [project name (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/shared/glossary#project-name) is set correctly in your
[project (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/shared/glossary#project)'s `spatialos.json`:

1. In the project's root directory, open `spatialos.json`. This file holds your project's global configuration.
2. In the `name` field, make sure the value is your assigned SpatialOS project name.

    You can find your project name in the [Console](https://console.improbable.io). It'll be something
    like `beta_someword_anotherword_000`.

> In our [example projects](https://github.com/spatialos), the
project name is set to `your_project_name_here`.

You **must** change this. If you don't:

* `spatial upload` will fail with the error `code = PermissionDenied desc = No permission to create assembly...`
* [deployments (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/shared/glossary#deploying) will fail with the error
`Encountered an error during command execution. no permissions to access Project...`

## 2. Initialize the project

Before you can do any development on your project, you need to initialise it:

0. Open a terminal, navigate to the root folder of your project and run `spatial worker codegen`.

0. If you are not using one of our [starter projects](https://github.com/spatialos), you must add `"SpatialOS"`
to your `PublicDependencyModuleNames` in your `Build.cs` file.

    This will set up your include paths next time you generate VS project files.
0. Locate the Unreal project file for your project. This can be found in `PROJECT_ROOT/workers/unreal/Game`.
0. Right-click on your project’s `.uproject` file and select **Switch Unreal Engine version**.
0. Switch engine versions to the source-built version you just built.
0. Run `spatial worker build`. This may take an hour or more.

This will build an assembly used for both local and cloud SpatialOS deployments.

> If you open your project with another version of Unreal Engine, it will rebuild the entire project.