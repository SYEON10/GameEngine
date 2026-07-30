#pragma once
#include "IManager.h"
#include <string> //TODO> pch에 있는데 왜 또 include 해야 하지?

class LogManager : public IManager<LogManager>
{
public:
	void StartUp() override;
	void ShutDown() override;

	void Log(const std::string& msg);
};

#define LOG_DEBUG(msg) \
	LogManager::Get().Log("[DEBUG] " + std::string(msg))

#define LOG_WARNING(msg) \
	LogManager::Get().Log("[WARNING] " + std::string(msg))

#define LOG_ERROR(msg) \
	LogManager::Get().Log("[ERROR] " + std::string(msg))

#define ENSURE_IFNOT(expr) \
	ENSURE_IFNOT_MSG(expr)

#define ENSURE_IFNOT_MSG(expr, msg) \
	if (!(expr)) { \
		__debugbreak(); \
	}