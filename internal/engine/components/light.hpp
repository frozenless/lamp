#pragma once

#include "types.hpp"

namespace lamp::components
{
	struct light
	{
		rgb color;
		f32 ambient;
		v3  position;
		f32 diffuse;
	};
}