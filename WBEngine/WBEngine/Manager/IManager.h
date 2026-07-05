#pragma once

template <class T>
class IManager {

public:
	static T& Get() { static T manager_; return manager_; };

protected:
	virtual void StartUp() = 0;
	virtual void ShutDown() = 0;
};