#include "LogManager.h"
#include <iostream>
#include <chrono>
#include <cstdarg>
#include <cstdio>

void LogManager::StartUp()
{
}

void LogManager::ShutDown()
{
}

void LogManager::Log(const FString& msg)
{
	auto now = std::chrono::system_clock::now();
	std::cout << format("{:%Y-%m-%d %H:%M:%S}", now) << " : " << msg << '\n';
}

FString LogManager::Format(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	va_list copy;
	va_copy(copy, args);
	const int len = vsnprintf(nullptr, 0, fmt, copy);
	va_end(copy);

	FString result;
	if (len > 0)
	{
		result.resize(len);
		vsnprintf(result.data(), len + 1, fmt, args);
	}
	va_end(args);
	return result;
}

