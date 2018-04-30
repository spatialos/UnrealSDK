# Unreal worker project structure

Code for the [Unreal workers](../introduction.md) - the UnrealWorker and the UnrealClient -
should be placed in the `workers/` directory as follows:

* [`workers/` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/shared/reference/project-structure#workers)
    * `unreal/` (you may use a different name)
        * [`spatialos.[worker_type].worker.json`](#spatialos-worker-type-worker-json)
        * `.gitignore` *(optional)*
        * `Game` (Containing your Unreal project)
            * `Config` (Containing your Unreal configuration ini files)
            * `Content`
            * `Source`
                * `ProjectName` (Containing the source code for your project)

## spatialos.[worker_type].worker.json

This file tells SpatialOS how to launch, and interact with the Unreal workers.

For details on the file format, see the [Configuring a worker (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/shared/worker-configuration/worker-configuration) section.

* [Example `spatialos.unreal.worker.json`]
    (https://github.com/spatialos/UnrealStarterProject/blob/master/workers/unreal/spatialos.UnrealClient.worker.json)  
* [Example `spatialos.UnrealWorker.worker.json`]
    (https://github.com/spatialos/UnrealStarterProject/blob/master/workers/unreal/spatialos.UnrealWorker.worker.json)
