#pragma once

#include "types.hpp"

namespace lamp
{
	struct Camera
	{
		Camera();

		void update_proj(const v2& size);
		void update_view();

		m4  view, proj;
		f32 fov;
	};
}