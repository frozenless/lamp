#pragma once

#include "types.hpp"

namespace lamp
{
	struct Material
	{
		rgb color;
		float shininess;

		gl::texture_ptr diffuse;
	};
}