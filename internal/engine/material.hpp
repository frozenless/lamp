#pragma once

#include "types.hpp"
#include "math/rgb.hpp"

namespace lamp
{
	struct Material
	{
		math::rgb color;
		float shininess = 32.0f;

		gl::texture_ptr diffuse;
	};
}