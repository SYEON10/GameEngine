#include "LogManager.h"
#include <iostream>
#include <chrono>

void LogManager::StartUp()
{
}

void LogManager::ShutDown()
{
}

void LogManager::Log(const string& msg)
{
	auto now = chrono::system_clock::now();
	cout << format("{:%Y-%m-%d %H:%M:%S}\n", now) << " : " << msg << '\n';
}

