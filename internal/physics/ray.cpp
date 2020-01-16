#include "ray.hpp"

namespace lamp
{
	Ray::Ray(const v3& origin, const v3& direction)
		: origin(origin)
		, direction(direction)
	{
	}
}