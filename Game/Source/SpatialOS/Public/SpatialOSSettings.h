// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
#pragma once
#include "SpatialOSWorkerConfigurationData.h"

#include "SpatialOSSettings.generated.h"

USTRUCT()
struct FSpatialWorkerOverrideSettings
{
  GENERATED_BODY()

  FSpatialWorkerOverrideSettings();

  /** SpatialOS worker configuration */
  UPROPERTY(EditAnywhere, config, Category = WorkerOverride)
  FSOSWorkerConfigurationData WorkerConfigurationData;

  /** Should viewport rendering be disabled? */
  UPROPERTY(EditAnywhere, config, Category = WorkerOverride)
  bool bDisableRendering;
};

UCLASS(config = Editor, defaultconfig)
class USpatialOSSettings : public UObject
{
  GENERATED_BODY()

public:
  USpatialOSSettings(const FObjectInitializer& ObjectInitializer);

  /** Should user worker configurations be used? */
  UPROPERTY(EditAnywhere, config, Category = Custom, meta = (ConfigRestartRequired = false))
  bool bUseUserWorkerConfigurations;

  /** Array of worker configurations */
  // clang-format off
  UPROPERTY(EditAnywhere, config, Category = Custom, meta = (ConfigRestartRequired = false, EditCondition = bUseUserWorkerConfigurations))
  // clang-format on
  TArray<FSpatialWorkerOverrideSettings> WorkerConfigurations;
};
