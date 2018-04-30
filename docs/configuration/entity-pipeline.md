# Entity pipeline

The **entity pipeline** is the mechanism which an Unreal worker uses to create and manage its representation of entities.

A SpatialOS deployment communicates with connected workers to instruct them when an entity or its components need to
be added or removed from the worker's view. For example, when an entity moves into or out of a worker's checkout area.
The entity pipeline provides an interface for calling user-defined functions in response to entity-related ops from SpatialOS.
As part of the Unreal SDK, we provide a standard implementation that should suit most people's needs.

## What the entity pipeline does

### Representing entities

Different workers may represent the same entity in different ways. In Unreal, workers represent entities using **Actors**
which are based on a **blueprint** or **C++ class**. Entities have a `Metadata` component with an `entity_type` string
property that is used to specify which Actor should be used to represent it.

### Placing entities in the world

All entities have a `Position` component that represents their canonical position in the world. It contains a vector of three
double values, and it's used to govern which entities a worker checks out, load-balancing, and more.

In most cases, entities need to be positioned on a worker in a way that meaningfully represents their `Position`
in the simulated world. However, there are some cases where you'd want to implement custom logic for transforming
positions - for example, if the world is very large or very small. Or you might want a secondary representation for
entity position.

### Handling component-related changes

When entities change, workers get instructions to make the relevant change; eg `AddComponent`, `RemoveComponent`,
`ComponentUpdate`, `AuthorityChange`. The entity pipeline handles these instructions, and uses the code
generated from your schemas to respond to these changes.

## Using the entity pipeline

### Pipeline blocks

The entity pipeline is made up of one or more **blocks** that together define how incoming operations should be handled.
Blocks must be added to the pipeline before a connection to a SpatialOS deployment is created. Any attempts to add blocks
after the connection has been established will result in an assertion.

### The default pipeline behaviour

The SDK currently comes with a basic implementation of an entity pipeline block that replaces the old `FEntitySpawner`
class. The `USimpleEntitySpawnerBlock` class provides the following behaviour:

#### Adding entities and components to the world

* Upon receiving an `AddEntity` operation, the block waits to receive the `AddComponent` operation for the `Position` and
`Metadata` components that correspond to that particular entity.
* The received `Metadata` and `Position` components are used to **spawn** an Actor in the world by using their respective
`entity_type` and `coords` properties.
* All future `AddComponent` operations are used to set the initial state of the corresponding spawned Actor's generated
`USpatialOsComponent`s.

#### Removing entities and components from the world

* Upon receiving a `RemoveComponent` operation, the Actor referring to this specific entity has `Disable()` called on its
corresponding generated `USpatialOsComponent`.
* Upon receiving a `RemoveEntity` operation, the Actor associated with this entity has `DestroyActor()` called on it.

### Adding blocks to your pipeline

Blocks are added to a pipeline like this:

```cpp
USimpleEntitySpawnerBlock* EntitySpawnerBlock = NewObject<USimpleEntitySpawnerBlock>();
EntitySpawnerBlock->Init(EntityRegistry);
SpatialOSInstance->GetEntityPipeline()->AddBlock(EntitySpawnerBlock);
```

The lifetime of all pipeline block objects are controlled the `USpatialOS` object once they've been added to the pipeline.

### Allowing the pipeline to process operations

In order to process all the operations that are being received, the pipeline must have its `ProcessOps()` function called
periodically. We recommend calling this every `Tick()`, similarly to the `SpatialOS` object. For example, in a `GameInstance` class:

```cpp
SpatialOSInstance->ProcessOps();
SpatialOSInstance->GetEntityPipeline()->ProcessOps(SpatialOSInstance->GetView(), SpatialOSInstance->GetConnection(), GetWorld());
```

## Customizing the entity pipeline

We're working towards making the entity pipeline **fully configurable** in order to provide complete control over how
and when entities exist in your game. As an example, you could create your own pipeline block that limits the number
of actors that are spawned in a particular game frame.
