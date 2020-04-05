#pragma once

#include "types.hpp"

namespace lamp
{
	class Random
	{
	public:
		Random() = delete;

		template<typename T> static T linear(T min, T max);

		static rgb  color();
		static void seed();
	};
}