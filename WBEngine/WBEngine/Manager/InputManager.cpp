#include "InputManager.h"

void InputManager::StartUp()
{
}

void InputManager::ShutDown()
{
}

bool InputManager::GetWindowsInput(UINT& msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
			case VK_ESCAPE:
				msg = WM_DESTROY;
				return false;
		}
	default:
		break;
	}

	return false;
}
