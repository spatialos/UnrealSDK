// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "SpatialOSComponentUpdater.generated.h"

class UEntityRegistry;

UCLASS()
class SPATIALOS_API USpatialOSComponentUpdater : public UObject
{
  GENERATED_BODY()

public:
  UFUNCTION()
  void UpdateComponents(UEntityRegistry* Registry, float DeltaSeconds);
};