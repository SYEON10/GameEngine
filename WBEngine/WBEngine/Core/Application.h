#pragma once
#include <wtypes.h>

class FWindows;
class FRenderer;

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class Application
{
public:
	Application(HINSTANCE hInstance, int nCmdShow);
	~Application();
	int Run(); //에러코드 반환

private:
	void MainLoop();

	void InitializeSystem();
	void StartSystem();
	void ShutdownSystem();

	FWindows* windows_;
	FRenderer* renderer_;
};

