#include "Client.h"

FClient::FClient()
{
}

FClient::~FClient()
{
}

int FClient::Run()
{
	//TODO> Windows 초기화

	InitializeSystem();
	StartSystem();
	MainLoop();
	ShutdownSystem();
	return 0;
}

void FClient::MainLoop()
{
	while(true)
	{
		//메인 루프 => 종료 조건 설정 요망
	}
}

void FClient::InitializeSystem()
{
}

void FClient::StartSystem()
{
}

void FClient::ShutdownSystem()
{
}
