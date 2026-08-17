#pragma once
#include "UObject.h"
#include "CoreMinimal.h"

class FObjectFactory
{
public:
	UObject* NewObject(UClass* uclass); //TODO> 일단 전체 오브젝트 저장은 폐기하고 CDO만 저장해서 호로록
};
