#pragma once

#include "types.hpp"
#include "math/rgb.hpp"

namespace lamp::components
{
	struct light
	{
		math::rgb color;

		float ambient  = 0.4f;
		float diffuse  = 0.7f;
		float specular = 0.65f;
	};
}