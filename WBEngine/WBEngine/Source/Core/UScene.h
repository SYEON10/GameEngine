#pragma once

#include "UObject.h"
#include "EngineMinimal.h"

class AActor;
class USceneComponent;

class UScene : public UObject
{
	GENERATE_BODY(UScene)

public:
	static const UScene* GetTestScene()
	{
		static const UScene* const TEST_SCENE = new UScene();
		return TEST_SCENE;
	}

public:
	inline TArray<TSharedPtr<AActor>>& GetObjects() { return objs_; };

private:
	TSharedPtr<USceneComponent> rootComponent_; //씬의 루트 컴포넌트
	TArray<TSharedPtr<AActor>> objs_; //씬에 배치된 오브젝트들
};

