#pragma once

namespace lamp::math
{
	struct rgb
	{
		explicit operator float*()
		{
		    return &r;
		}

		float r = 1.0f;
		float g = 1.0f;
		float b = 1.0f;
	};
}