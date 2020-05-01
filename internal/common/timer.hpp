#pragma once

#include "dependencies.hpp"

namespace lamp
{
	using clock = std::chrono::high_resolution_clock;
	using time  = std::chrono::time_point<clock>;

	class Timer
	{
	public:
		Timer();

		[[nodiscard]]
		float elapsed() const;
		void  restart();

	private:
		time _start;
	};
}