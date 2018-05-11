// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "ComponentUpdateOpWrapperBase.h"
#include "EngineMinimal.h"
#include "ComponentUpdateQueue.generated.h"

USTRUCT(BlueprintType)
struct FComponentUpdateQueue
{
  GENERATED_BODY()

  void AddToQueue(UComponentUpdateOpWrapperBase* Update)
  {
    Updates.AddUnique(Update);
  }

  TArray<UComponentUpdateOpWrapperBase*>& GetQueue()
  {
    return Updates;
  }

  void Empty()
  {
    Updates.Empty();
  }

private:
  UPROPERTY()
  TArray<UComponentUpdateOpWrapperBase*> Updates;
};