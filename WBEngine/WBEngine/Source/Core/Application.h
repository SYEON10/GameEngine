#pragma once
#include <wtypes.h>

class FWindows;
class FRenderer;

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

	//라이프사이클
	void Update(float deltaTime);
	void FixedUpdate();

	//인풋 처리
	bool ProcessInput(MSG* msg);

	FWindows* windows_;
	FRenderer* renderer_;
};

