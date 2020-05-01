#pragma once

#include "types.hpp"
#include "math/rgb.hpp"

namespace lamp
{
	class Random
	{
	public:
		Random() = delete;

		template<typename T> static T linear(T min, T max);

		static math::rgb color();
		static void      seed();
	};
}