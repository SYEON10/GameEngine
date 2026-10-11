#include "Application.h"
#include "FWindows.h"
#include "Time.h"
#include "Graphics/FRenderer.h"
#include "../Manager/InputManager.h"
#include "../Manager/LogManager.h"

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
	//인풋 테스트
	//InputManager::Get().Bind(FInputEvent(InputEventType::KeyDown, EKeyCode::KEY_W), []() {LOG_DEBUG("KEYDOWN wwwwww"); });

    MSG msg;
	Time::Initialize();
	float accumulator = 0.0f;
    while (true)
    {
		if (ProcessInput(&msg) == false) {
			break;
		}

		float dt = Time::UpdateDeltaTime();
		accumulator += dt;

		while (accumulator >= Time::FIXED_DELTATIME) {   // 부족하면 0번 실행, 대기 없음
			FixedUpdate();
			accumulator -= Time::FIXED_DELTATIME;
		}

		Update(dt);
		renderer_->RenderLoop();
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

void Application::Update(float deltaTime)
{
	LOG_DEBUG("DeltaTime: %f, TotalTime: %f", deltaTime, Time::TotalTime());
}

void Application::FixedUpdate()
{
	LOG_DEBUG("FixedUpdate: %f", Time::TotalTime());
}

bool Application::ProcessInput(MSG* msg)
{
	if (PeekMessage(msg, NULL, 0, 0, PM_REMOVE)) {
		TranslateMessage(msg); //사용자가 알아들을 수 있는 메시지로 변환
		DispatchMessage(msg);	//WinProc으로 메시지 전달

		if (msg->message == WM_QUIT) {
			return false;
		}
	}

	return true;
}
