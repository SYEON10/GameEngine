#pragma once
#include "IManager.h"
#include "ManagerMinimal.h"

class LogManager : public IManager<LogManager>
{
public:
	void StartUp() override;
	void ShutDown() override;

	void Log(const FString& msg);

	// printf 스타일 포맷 → FString
	static FString Format(_Printf_format_string_ const char* fmt, ...);
};

#define LOG_DEBUG(...) \
	LogManager::Get().Log("[DEBUG] " + LogManager::Format(__VA_ARGS__))

#define LOG_WARNING(...) \
	LogManager::Get().Log("[WARNING] " + LogManager::Format(__VA_ARGS__))

#define LOG_ERROR(...) \
	LogManager::Get().Log("[ERROR] " + LogManager::Format(__VA_ARGS__))

#define ENSURE_IFNOT(expr) \
	ENSURE_IFNOT_MSG(expr)

#define ENSURE_IFNOT_MSG(expr, msg) \
	if (!(expr)) { \
		__debugbreak(); \
	}