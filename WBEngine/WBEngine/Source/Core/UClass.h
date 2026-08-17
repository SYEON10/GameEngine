#pragma once

#include "CoreMinimal.h";

class UClass
{
	friend FObjectFactory;

	//TODO> Type을 저장해야 해...

private:
	inline void SetCDOIndex(const INT64 index) { CDOIndex_ = index; }
	inline TOptional<INT64> GetCDOIndex() const { return CDOIndex_; }

	TOptional<INT64> CDOIndex_;
};

