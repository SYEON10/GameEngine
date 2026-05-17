#pragma once


class FObjectFactory
{
public:
	template<typename T, typename... Args>
	static T* ConstructObject(Args&&... args)
	{
		return new T(std::forward<Args>(args)...);
	}
};

