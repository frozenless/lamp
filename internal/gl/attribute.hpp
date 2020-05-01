#pragma once

#include "types.hpp"

namespace lamp::gl
{
	struct attribute
	{
		attribute(uint32_t count, uint32_t type, uint32_t offset) noexcept;

		uint32_t count;
		uint32_t type;
		uint32_t offset;
	};
}
