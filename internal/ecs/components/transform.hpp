#pragma once

#include "types.hpp"

namespace lamp::ecs::components
{
	struct Transform
	{
		Transform() : world(1.0f) { }

		m4 world;
	};
}