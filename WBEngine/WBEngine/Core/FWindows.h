#pragma once
#include <wtypes.h>


//Windows 초기화, 창 생성, Windows 메시지 처리를 담당
class FWindows
{
public:
	FWindows(HINSTANCE hInstance, int nCmdShow);
	virtual ~FWindows();

	void ShowWindow();
	void CreateConsoleWindow(); // Optional: Create a console window for debugging

	HWND GetHWND() const { return hwnd_; }

private:
	static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
	float main_scale = 1.f; // Default scale value, you may want to set this based on your needs

	static UINT width_, height_;

	HWND hwnd_;
	WNDCLASSEXW wc_;
	int nCmdShow_;
};

