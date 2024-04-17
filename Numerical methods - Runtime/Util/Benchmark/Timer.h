#pragma once

#include <iostream>
#include <chrono>

#define _APP_PROFILING_

#ifdef _APP_PROFILING_
#define PROFILE_SCOPE(name) Timer timer##__LINE__(name)
#define PROFILE_APP_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)
#else
#define PROFILE_SCOPE(name)
#define PROFILE_APP_FUNCTION()
#endif

class Timer
{
public:
	Timer(const char* name);
	~Timer();

private:
	const char* m_Name;
	std::chrono::time_point<std::chrono::steady_clock> m_StartTimePoint;
	bool m_Stopped;

	void Stop();
};

