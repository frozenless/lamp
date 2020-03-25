#include "timer.hpp"

namespace lamp
{
	Timer::Timer()
		: _start(clock::now())
	{
	}

	void Timer::restart()
	{
		_start = clock::now();
	}

	float Timer::elapsed() const
	{
		const  auto end = clock::now();
		return std::chrono::duration<float, std::milli>(end - _start).count();
	}
}