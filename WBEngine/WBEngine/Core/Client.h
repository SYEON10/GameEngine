#pragma once

class FClient
{
public:
	FClient();
	~FClient();
	int Run(); //에러코드 반환

private:
	void MainLoop();
	void InitializeSystem();
	void StartSystem();
	void ShutdownSystem();
};

