#include "Application.h"
#include "FWindows.h"
#include "FRenderer.h"

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
	//TODO> Windows ÃÊ±âÈ­

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
    bool done = false;
    while (!done)
    {
        
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
