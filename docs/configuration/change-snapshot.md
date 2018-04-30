# Changing the starting state of the world

When you deploy a SpatialOS project, the initial state of the SpatialOS world is defined by a
[snapshot (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/shared/glossary#snapshot). The example projects come with a default snapshot
- `snapshots/default.snapshot` - but you can modify it or create new ones.

In the Unreal Starter Project, there's an **Unreal commandlet** to generate a snapshot, located
in `workers/unreal/Game/Source/StarterProject/ExportSnapshotCommandlet.cpp`.
The commandlet uses the [C++ worker API (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/using#snapshots).

The commandlet creates a spawner entity that will exist in the world
when the game starts. You can add your own entities by using the SpatialOS components and Unreal blueprints you
defined. When you're happy with your changes, build your new snapshot:

1. Compile your C++ changes.
2. On the root of your project run `./generatesnapshot.sh` (this will run the Unreal commandlet and
overwrite `snapshots/default.snapshot`).

> You can change the snapshot save name or location by modifying it in the Commandlet code.

Once your new snapshot is built, you can launch your new world with
`spatial local launch --snapshot=<your_snapshot_name>.snapshot`.
