#pragma once

#include <glm/gtc/random.hpp>

namespace lamp
{
	template<typename T> T random(const T min, const T max)
	{
		return glm::linearRand(min, max);
	}
}