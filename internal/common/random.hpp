#pragma once

#include "types.hpp"
#include "math/rgb.hpp"

#include <glm/gtc/random.hpp>

namespace lamp
{
	class Random
	{
	public:
		Random() = delete;

		template<typename T> static T linear(T min, T max)
        {
            return glm::linearRand(min, max);
        }

		static math::rgb color();
		static void      seed();
	};
}