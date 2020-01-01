#pragma once

#include "types.hpp"

namespace lamp
{
	struct Light
	{
		rgb color;
		v3  position;

		f32 ambient;
		f32 diffuse;
	};
}