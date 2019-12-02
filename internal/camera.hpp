#pragma once

#include "util.hpp"

namespace lamp
{
	struct Camera
	{
		void update_proj(const v2 &size);
		void update_view();

		m4 view, proj;
	};
}