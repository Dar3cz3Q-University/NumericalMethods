#include "Timer.h"

Core_Timer::Core_Timer(const char* name)
	: m_Name(name), m_Stopped(false)
{
	m_StartTimePoint = std::chrono::high_resolution_clock::now();
}

Core_Timer::~Core_Timer() {
	if (!m_Stopped)
		Stop();
}

void Core_Timer::Stop() {
	auto endTimePoint = std::chrono::high_resolution_clock::now();

	auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
	auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

	auto duration = end - start;

	std::ofstream file("time.log", std::ios_base::app);

	file << m_Name << ": " << duration << " microseconds" << std::endl;

	file.close();

	m_Stopped = true;
}
