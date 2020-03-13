#pragma once

#include "types.hpp"

namespace lamp::gl
{
	struct Attribute
	{
		Attribute(u32 count, u32 type, u32 offset) noexcept;

		u32 count;
		u32 type;
		u32 offset;
	};
}
