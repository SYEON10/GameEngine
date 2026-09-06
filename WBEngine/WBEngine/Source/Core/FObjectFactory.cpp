#include "FObjectFactory.h"

/*UObject* FObjectFactory::NewObject(FTypeInfo* classInfo)
{
	static INT64 CDOIndex = INDEX_NONE;
	static TArray<UObject*> CDObjects;

	if (INT64 index = uclass->GetCDOIndex().has_value()) {
		return CDObjects[index]; //TODO> memcpy로 반환해야...
	}

	uclass->SetCDOIndex(++CDOIndex);
	//TODO> UClass 안에 저장된 타입으로 생성자 호출해서 반환해야 함

	return classInfo->constructor();

	return nullptr;
}*/
