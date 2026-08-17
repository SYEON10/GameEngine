#include "LogManager.h"
#include <iostream>
#include <chrono>

void LogManager::StartUp()
{
}

void LogManager::ShutDown()
{
}

void LogManager::Log(const FString& msg)
{
	auto now = std::chrono::system_clock::now();
	std::cout << format("{:%Y-%m-%d %H:%M:%S}\n", now) << " : " << msg << '\n';
}

