#pragma once

#include "types.hpp"

namespace lamp
{
	struct Material
	{
		explicit Material(const rgb& color = rgb(1.0f));

		gl::texture_ptr texture;
		rgb color;
	};
}