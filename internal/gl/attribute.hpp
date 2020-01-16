#pragma once

#include "types.hpp"

namespace lamp::gl
{
	struct Attribute
	{
		Attribute(int index, int count, u32 type, int offset);

		int index;
		int offset;
		int count;
		u32 type;
	};
}
