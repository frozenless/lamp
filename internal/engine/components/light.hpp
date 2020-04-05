#pragma once

#include "types.hpp"

namespace lamp::components
{
	struct light
	{
		rgb   color;
		float ambient;
		v3    position;
		float diffuse;
		float specular;
	};
}