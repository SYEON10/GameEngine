#pragma once
#include "UClass.h"

class UObject
{
public:
	virtual ~UObject() = default;

	inline UClass* GetClass() const { return classPrivate; };

private:
	UClass* classPrivate = nullptr;
};

