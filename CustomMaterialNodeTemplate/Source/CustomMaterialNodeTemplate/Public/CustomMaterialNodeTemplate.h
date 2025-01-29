// Copyright 2025 Andrew Laptev. All Rights Reserved.
// Fill out your own copyright notice.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FCustomMaterialNodeTemplateModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
