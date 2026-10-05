#pragma once

#include "UObject.h"
#include "EngineMinimal.h"

class UObject;

class USceneComponent : public UObject
{
	GENERATE_BODY(USceneComponent)

public:
	void AttachParent(TSharedPtr<USceneComponent> parentComponent);
	void AttachChildren(TSharedPtr<USceneComponent> childComponent);
	void DetachChildren(TSharedPtr<USceneComponent> childComponent);

protected:

	TSharedPtr<USceneComponent> parentComponent_;
	TArray<USceneComponent> childComponents_;

	// TRS
	FVector3 localPos_;
	FVector3 localRot_;
	FVector3 localScale_;
};

