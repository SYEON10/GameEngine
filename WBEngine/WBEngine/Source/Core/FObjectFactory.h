#pragma once
#include "CoreMinimal.h"

class UObject;

struct FUObjectInfo {
	explicit FUObjectInfo(UObject* obj)
		: obj_(obj) {}

	UObject* obj_;
};

template <typename T> requires std::derived_from<T, UObject>
T* NewObject() {
	T* obj = new T();
	//추후 CDO 작업 할 때
	//UClass* privateClass = T::GetClass();
	//privateClass->GetCDOIndex();
	//obj->SetIndex();
	//UObjectArray.push_back(FUObjectInfo(obj));
	return obj;
}

class FObjectFactory
{
private:
};
