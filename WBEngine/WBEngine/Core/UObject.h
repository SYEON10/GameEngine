#pragma once

class UObject
{
public:
	virtual ~UObject() = default;

	FORCEINLINE UClass* GetClass() const { return classPrivate; };

private:
	UClass* classPrivate = nullptr;
};

