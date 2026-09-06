#pragma once

#include "UObject.h"
#include "EngineMinimal.h"

class UObject;

class USceneComponent : public UObject
{
	GENERATE_BODY(USceneComponent)

protected:
	FVector localPos_;
	FVector localRot_;
	FVector localScale_;
};

