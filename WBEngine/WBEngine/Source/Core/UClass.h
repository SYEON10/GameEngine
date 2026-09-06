#pragma once

#include "UObjectMinimal.h"

class UClass
{
	friend class FObjectFactory;
	
public:
	UClass();

private:
	inline void SetCDOIndex(const INT64 index) { CDOIndex_ = index; }
	inline TOptional<INT64> GetCDOIndex() const { return CDOIndex_; }

	TOptional<INT64> CDOIndex_;
};

