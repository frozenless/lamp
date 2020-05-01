#include "rgb.hpp"

namespace lamp::math
{
	rgb::rgb(const float value)
		: r(value)
		, g(value)
		, b(value)
	{
	}

	rgb::rgb(const float r, const float g, const float b)
		: r(r)
		, g(g)
		, b(b)
	{
	}

	rgb::operator float*()
	{
		return &r;
	}
}