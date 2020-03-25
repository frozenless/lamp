#pragma once

#include "dependencies.hpp"

namespace lamp
{
	using clock = std::chrono::high_resolution_clock;

	class Timer
	{
	public:
		Timer();

		[[nodiscard]]
		float elapsed() const;
		void  restart();

	private:
		std::chrono::time_point<clock> _start;
	};
}