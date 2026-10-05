#pragma once

#include "UObject.h"
#include "EngineMinimal.h"

class USceneComponent;

class AActor : public UObject
{
	GENERATE_BODY(AActor)

public:
	inline TSharedPtr<USceneComponent> GetSceneComponent() { return rootComponent_; };

protected:
	TSharedPtr<USceneComponent> rootComponent_;
};

