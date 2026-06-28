#include "Application.h"

Application::Application(HINSTANCE hInstance, int nCmdShow)
{
}

Application::~Application()
{
}

int Application::Run()
{
	//TODO> Windows 초기화

	InitializeSystem();
	StartSystem();
	MainLoop();
	ShutdownSystem();
	return 0;
}

void Application::MainLoop()
{
	while(true)
	{
		//메인 루프 => 종료 조건 설정 요망
	}
}

void Application::InitializeSystem()
{
}

void Application::StartSystem()
{
}

void Application::ShutdownSystem()
{
}

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (wParam == SIZE_MINIMIZED)
            return 0;
        g_ResizeWidth = (UINT)LOWORD(lParam); // Queue resize
        g_ResizeHeight = (UINT)HIWORD(lParam);
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}