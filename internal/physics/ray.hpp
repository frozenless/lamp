#pragma once

#include "types.hpp"

namespace lamp
{
	struct Ray
	{
		Ray(const v3& origin, const v3& direction);

		v3 origin;
		v3 direction;
	};
}