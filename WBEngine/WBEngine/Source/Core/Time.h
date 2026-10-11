#pragma once

#include <chrono>
#include <cstdint>
#include <algorithm>

class Time {

	friend class Application;

public:
	static inline float DeltaTime() {
		return (std::min)(deltaTime_ * timeScale_, MAX_DELTATIME);
	}

	static inline float UnscaledDeltaTime() {
		return deltaTime_;
	}

	static inline double TotalTime() {
		return totalTime_;
	}

	static inline double UnscaledTotalTime() {
		return unscaledTotalTime_;
	}

	static inline float GetTimeScale() {
		return timeScale_;
	}

	static inline void SetTimeScale(float timeScale) {
		timeScale_ = (std::max)(timeScale, 0.0f);
	}

private:
	// 시작 시점 기록. 첫 프레임의 DeltaTime이 튀지 않도록 MainLoop 진입 전에 한 번 호출한다.
	static void Initialize();

	// 프레임마다 한 번 호출하여 DeltaTime을 갱신한다.
	static float UpdateDeltaTime();

	static float timeScale_;	//TODO 추후 조정 기능 추가
	static float deltaTime_;
	static double totalTime_;
	static double unscaledTotalTime_;
	static std::chrono::steady_clock::time_point lastTime_;
	static constexpr float MAX_DELTATIME = 0.02f;	//TODO 추후 조정 기능 추가
	static constexpr float FIXED_DELTATIME = 0.02f;	//TODO 추후 조정 기능 추가
};
