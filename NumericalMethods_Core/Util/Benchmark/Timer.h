#pragma once

#include <iostream>
#include <chrono>
#include <fstream>

#define _CORE_PROFILING_

#ifdef _CORE_PROFILING_
#define PROFILE_SCOPE(name) Core_Timer timer##__LINE__(name)
#define PROFILE_CORE_FUNCTION() PROFILE_SCOPE(__FUNCTION__)
#else
#define PROFILE_SCOPE(name)
#define PROFILE_CORE_FUNCTION()
#endif

class Core_Timer
{
public:
	Core_Timer(const char* name);
	~Core_Timer();

private:
	const char* m_Name;
	std::chrono::steady_clock::time_point m_StartTimePoint;
	bool m_Stopped;

	void Stop();
};
