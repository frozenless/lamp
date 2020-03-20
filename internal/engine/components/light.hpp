#pragma once

#include "types.hpp"

namespace lamp::components
{
	struct Light
	{
		rgb color;
		f32 ambient;
		v3  position;
		f32 diffuse;
	};
}