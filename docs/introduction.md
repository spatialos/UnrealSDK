![Unreal SDK documentation](assets/unreal-sdk-header.png)

# Introduction to the Unreal SDK
You can use Unreal Engine 4 as a [worker (SpatialOS documentation)](https://docs.improbable.io/reference/13.0/shared/glossary#worker)
in a SpatialOS project to add physics, game logic and visualization to a SpatialOS game. We provide an
Unreal SDK  (beta) to make it easier to use Unreal as a worker.

Listed below are a few specific issues we're aware of.

## Known issues
* Only Windows works for development.
* Not all schema features work. Current limitations are:
  * Nested type definitions won't work.
  * Enums may only assume values within the range 0 - 255.
  * Some schema types won't work in blueprints due to limitations in the scripting engine:
  `uint32`, `uint64`, `int64`, `sint32`, `sint64`, `fixed32`, `fixed64`, `sfixed32`, `sfixed64`, `double` 
  and `improbable.vector3d`.
  * Commands with the same name and delegate type (request type + response type) are not supported in 
  schema definition, even if they are defined in different components.
  * Schema types and components with the same name as UnrealEngine UStructs and UClasses will fail to compile. 
  For example `type Transform {}` conflicts with Unreal's `FTransform`.
* When running a cloud deployment, clients may not be able to connect to your game due to a bug in the Unreal source code.
If you encounter this, please patch [this pull request](https://github.com/EpicGames/UnrealEngine/pull/4206) into 
your Unreal Engine source code and [rebuild Unreal](get-started/setup/win.md#3-set-up-unreal). Afterwards, you 
need to build your project using `spatial build`.

## License
* See the [license](../LICENSE.md).

## Documentation
* See the SpatialOS documentation at [docs.improbable.io](https://docs.improbable.io/).
* See the Unreal SDK documentation on [GitHub](start-here-table-of-contents.md).


## Getting started
To get started, [set up your machine](get-started/setup/win.md).

Once you've done that, see the rest of the [documentation](start-here-table-of-contents.md) to learn how to:

- [Set up a project](develop/set-up-unreal-project.md)
- [Build](develop/build.md)
- [Running your project](develop/debug-and-iterate.md)
- [Change the starting state of the world](configuration/change-snapshot.md)
- [Create entity blueprints](interact-with-world/entity-blueprints.md)
- [Create and delete entities](interact-with-world/create-delete-entities.md)
- [Querying the world](interact-with-world/query-world.md)
- [Make changes to components and call commands](interact-with-world/interact-components.md)

## The relationship between SpatialOS and Unreal
When you're using Unreal on its own, it's the canonical source of truth about the game world. What's in Unreal is in the
game world.

**When you use Unreal as a SpatialOS worker**, this isn't true any more: the canonical source of truth is the world of
the SpatialOS simulation, and the entities in that world. Each Unreal worker has a view onto part of that world. It
represents the entities from SpatialOS as [(entity) blueprints](interact-with-world/entity-blueprints.md).

An Unreal worker can do whatever it likes to its own representation of the world, run whatever logic it likes, etc etc. **But**,
if the worker doesn't send these changes to SpatialOS in the form of an update to a SpatialOS entity, those changes will only
ever be local: they can't be seen by any other worker.

Sometimes this is fine. For example, if on a client worker, you are making a purely visual change, no other
worker needs to know about it, so it doesn't need to be represented in SpatialOS.

But for anything else that another worker would need to be aware of, those changes must be made
to a SpatialOS entity.

### How can Unreal workers change the SpatialOS world?
They can:

* create entities
* delete entities
* set properties of an entity
* trigger an event on an entity
* send a command to an entity

For more information, see [Creating and deleting entities](interact-with-world/create-delete-entities.md)
and [Interacting with entity components](interact-with-world/interact-components.md).

### How do Unreal workers get information about the SpatialOS world?
Within the worker's area of interest, SpatialOS will send the worker updates about changes to
components/entities it can read. So a worker can:

* get the value of a property
* watch for events being triggered
* watch for commands being called

Outside its area of interest, a worker can find out about the world by querying for entities.

For more information, see [Interacting with entity components](interact-with-world/interact-components.md) and
[Querying the world](interact-with-world/query-world.md).
