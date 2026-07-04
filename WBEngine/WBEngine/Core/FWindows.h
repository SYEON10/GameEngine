#pragma once
#include <wtypes.h>

class FWindows
{
public:
	FWindows(HINSTANCE hInstance, int nCmdShow, WNDPROC wndProc);
	virtual ~FWindows();

	HWND GetHWND() const { return hwnd_; }

private:
	float main_scale = 1.f; // Default scale value, you may want to set this based on your needs
	HWND hwnd_;
	WNDCLASSEXW wc_;
};

