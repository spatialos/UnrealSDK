// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SpatialOSModule.h"

#include "ModuleManager.h"
#include "Paths.h"
#include "PlatformProcess.h"
#include "SpatialOSSettings.h"
#include "UObjectBase.h"

#define LOCTEXT_NAMESPACE "FSpatialOSModule"

DEFINE_LOG_CATEGORY(LogSpatialOSModule);

IMPLEMENT_MODULE(FSpatialOSModule, SpatialOS)

void FSpatialOSModule::StartupModule()
{
  RegisterSettings();
}

void FSpatialOSModule::ShutdownModule()
{
  if (UObjectInitialized())
  {
    UnregisterSettings();
  }
}

void FSpatialOSModule::RegisterSettings()
{
  if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
  {
    ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer("Project");

    SettingsContainer->DescribeCategory(
        "SpatialOS", LOCTEXT("RuntimeWDCategoryName", "SpatialOS"),
        LOCTEXT("RuntimeWDCategoryDescription", "Configuration for the SpatialOS module"));

    ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings(
        "Project", "SpatialOS", "SpatialOS", LOCTEXT("RuntimeGeneralSettingsName", "SpatialOS"),
        LOCTEXT("RuntimeGeneralSettingsDescription", "Base configuration for SpatialOS module."),
        GetMutableDefault<USpatialOSSettings>());

    if (SettingsSection.IsValid())
    {
      SettingsSection->OnModified().BindRaw(this, &FSpatialOSModule::HandleSettingsSaved);
    }
  }
}

void FSpatialOSModule::UnregisterSettings()
{
  if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
  {
    SettingsModule->UnregisterSettings("Project", "SpatialOS", "SpatialOS");
  }
}

bool FSpatialOSModule::HandleSettingsSaved()
{
  USpatialOSSettings* Settings = GetMutableDefault<USpatialOSSettings>();
  Settings->SaveConfig();

  return true;
}

#undef LOCTEXT_NAMESPACE
