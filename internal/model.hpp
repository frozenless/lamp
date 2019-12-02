#pragma once

#include "common.hpp"

namespace lamp
{
	struct Model
	{
		explicit Model(const v3 &position = v3(0.0f), f32 scale = 1.0f) noexcept;

		void update();

		meshPtr mesh;

		m4 world;
		v3 position;
		v3 color;

		f32 scale;
	};
}