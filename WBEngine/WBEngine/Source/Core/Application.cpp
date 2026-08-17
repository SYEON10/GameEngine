#include "Application.h"
#include "FWindows.h"
#include "Graphics/FRenderer.h"
#include "../Manager/InputManager.h";
#include "../Manager/LogManager.h";

#include "../Editor/ImGUI/imgui.h"
#include "../Editor/ImGUI/imgui_impl_win32.h"
#include "../Editor/ImGUI/imgui_impl_dx11.h"
#include <d3d11.h>
#include <tchar.h>
#include <windows.h> 
#include <windowsx.h> 

Application::Application(HINSTANCE hInstance, int nCmdShow)
{
	windows_ = new FWindows(hInstance, nCmdShow);
    renderer_ = new FRenderer();
}

Application::~Application()
{
    
}

int Application::Run()
{
	//TODO> Windows 초기화

	windows_->CreateConsoleWindow();
	windows_->ShowWindow();
    renderer_->Initializer(windows_->GetHWND(), 1280, 800);

	InitializeSystem();
	StartSystem();
	MainLoop();
	ShutdownSystem();
	return 0;
}

void Application::MainLoop()
{
    MSG msg;
    while (true)
    {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg); //사용자가 알아들을 수 있는 메시지로 변환
			DispatchMessage(&msg);	//WinProc으로 메시지 전달

			if (msg.message == WM_QUIT) {
				break;
			}
		}
		else {
			renderer_->RenderLoop();
		}
    }
}

void Application::InitializeSystem()
{
	LogManager::Get().StartUp();
	InputManager::Get().StartUp();
}

void Application::StartSystem()
{
}

void Application::ShutdownSystem()
{

}
