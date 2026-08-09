#pragma once

#include "IManager.h"
#include <wtypes.h>

class InputManager : public IManager<InputManager>
{
	friend class IManager<InputManager>;

private:
	InputManager() = default;

public:
	void StartUp() override;
	void ShutDown() override;

	bool GetWindowsInput(UINT& msg, WPARAM wParam, LPARAM lParam);
};

