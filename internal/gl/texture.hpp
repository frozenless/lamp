#pragma once

#include "util.hpp"

namespace lamp::gl
{
	struct Texture
	{
		void bind() noexcept;

		u32 id;
	};
}
