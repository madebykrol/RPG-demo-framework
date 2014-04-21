// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#ifndef __TOPDOWNEXAMPLE_H__
#define __TOPDOWNEXAMPLE_H__

#include "Engine.h"
#include "EngineUserInterfaceClasses.h"
#include "EngineKismetLibraryClasses.h"
#include "TopDownExampleClasses.h"
#include "../../../../../../Source/TopDownExample/TopDownExampleCharacter.h"



DECLARE_LOG_CATEGORY_EXTERN(LogTopDownExample, Log, All);

#define COLLISION_WEAPON		ECC_GameTraceChannel1
#define COLLISION_PROJECTILE	ECC_GameTraceChannel2
#define COLLISION_ALL			ECC_WorldStatic


#endif
