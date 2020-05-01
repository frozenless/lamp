#pragma once

namespace lamp::math
{
	struct rgb
	{
		rgb(float r, float g, float b);

		explicit rgb(float value = 1.0f);
		explicit operator float*();

		float r, g, b;
	};
}