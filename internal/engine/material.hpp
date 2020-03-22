#pragma once

#include "types.hpp"

namespace lamp
{
	struct Material
	{
		explicit Material(const rgb& color = glm::one<rgb>());

		gl::texture_ptr texture;
		rgb color;
	};
}