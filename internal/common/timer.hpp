#pragma once

#include "dependencies.hpp"

namespace lamp
{
	class Timer
	{
	public:
		void start();
		void stop();

		std::ofstream& operator<<(std::ofstream& os);

	private:

	};
}