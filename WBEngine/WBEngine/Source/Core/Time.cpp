#include "Time.h"

float Time::timeScale_ = 1.0f;
float Time::deltaTime_ = 0.0f;
double Time::totalTime_ = 0.0;
double Time::unscaledTotalTime_ = 0.0;
std::chrono::steady_clock::time_point Time::lastTime_ = std::chrono::steady_clock::now();

void Time::Initialize()
{
	lastTime_ = std::chrono::steady_clock::now();
	deltaTime_ = 0.0f;
	totalTime_ = 0.0;
	unscaledTotalTime_ = 0.0;
}

float Time::UpdateDeltaTime()
{
	auto now = std::chrono::steady_clock::now();
	deltaTime_ = std::chrono::duration<float>(now - lastTime_).count();
	lastTime_ = now;

	unscaledTotalTime_ += deltaTime_;
	totalTime_ += DeltaTime();

	return DeltaTime();
}
