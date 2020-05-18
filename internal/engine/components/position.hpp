#pragma once

namespace lamp::components
{
	struct position
	{
        explicit operator float*()
        {
            return &x;
        }

		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
	};
}