#pragma once

#include "types.hpp"

namespace lamp::gl
{
	struct Object
	{
		Object();

		virtual void bind() const noexcept = 0;

		handle id;
	};
}
