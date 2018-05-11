// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Developer/Settings/Public/ISettingsContainer.h"
#include "Developer/Settings/Public/ISettingsModule.h"
#include "Developer/Settings/Public/ISettingsSection.h"
#include "ModuleManager.h"
#include "SpatialOSSdkLoader.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSpatialOSModule, Log, All);

class FSpatialOSModule : public IModuleInterface
{
public:
  void StartupModule() override;
  void ShutdownModule() override;

private:
  void RegisterSettings();
  void UnregisterSettings();
  bool HandleSettingsSaved();

  FSpatialOSSdkLoader Loader;
};
