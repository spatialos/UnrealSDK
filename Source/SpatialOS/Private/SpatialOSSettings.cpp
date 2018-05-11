// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SpatialOSSettings.h"

FSpatialWorkerOverrideSettings::FSpatialWorkerOverrideSettings() : bDisableRendering(false)
{
}

USpatialOSSettings::USpatialOSSettings(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer), bUseUserWorkerConfigurations(false)
{
}
