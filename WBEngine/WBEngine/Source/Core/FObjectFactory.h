#pragma once


class FObjectFactory
{
public:
	static UObject* ConstructObject(const UClass* uclass)
	{
		return new T(std::forward<Args>(args)...);
	}

private:
	TArray<UObject*> Objects;
};

