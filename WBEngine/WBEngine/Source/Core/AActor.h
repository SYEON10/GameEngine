#pragma once

#include "UObject.h"
#include "EngineMinimal.h"

class USceneComponent;

class AActor : public UObject
{
	GENERATE_BODY(AActor)

public:
	inline TSharedPtr<USceneComponent> GetSceneComponent() { return sceneComponent_; };

protected:
	TSharedPtr<USceneComponent> sceneComponent_;
};

