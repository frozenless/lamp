#pragma once

#include "types.hpp"

namespace lamp
{
	struct Transform
	{
		void from(const v3& p, f32 s = 1.0f);
		void update();

		m4  world;

		v3  position;
		f32 scale;
	};
}
