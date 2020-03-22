#pragma once

#include "common/random.hpp"

#include <glm/gtc/random.hpp>

namespace lamp
{
	template<typename T> T Random::linear(const T min, const T max)
	{
		return glm::linearRand(min, max);
	}
}