#pragma once

#include "InfraStructure.h"

#include <chrono>
#include <vector>
#include <functional>

namespace ESGI
{
	__declspec(dllexport) struct TimeSource
	{
		using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
		static TimePoint now() { return std::chrono::high_resolution_clock::now(); }
	};

	__declspec(dllexport) struct Timer
	{
		double Delay;
		double CurrentTime;
		bool Repeat;
	};

	__declspec(dllexport) struct Clock : public InfraStructure
	{
		std::vector<std::pair<Timer, std::function<void()>>> m_Timers;

		TimeSource::TimePoint TimePointAtStartup;
		TimeSource::TimePoint PreviousTimePoint;
		TimeSource::TimePoint CurrentTimePoint;

		double TimeSinceStartup = 0.0;
		double ElapsedTime = 0.0;

		__declspec(dllexport) bool Initialize() final;
		__declspec(dllexport) void DeInitialize() final;

		// ce n'est pas une fonction virtuelle !
		__declspec(dllexport) void Update();

		__declspec(dllexport) void AddTimer(Timer& timer, std::function<void(void)> event)
		{
			m_Timers.push_back({ timer, event });
		}
	};
}