#pragma once

#include "types.hpp"

namespace lamp::gl
{
	struct Attribute
	{
		Attribute(int count, u32 type, int offset);

		int count;
		int offset;
		u32 type;
	};
}
