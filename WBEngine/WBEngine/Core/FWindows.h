#pragma once
#include <wtypes.h>

class FWindows
{
public:
	FWindows(HINSTANCE hInstance, int nCmdShow, WNDPROC wndProc);

private:
	float main_scale = 1.f; // Default scale value, you may want to set this based on your needs
	HWND hwnd_;
};

