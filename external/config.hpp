#pragma once

#include "types.hpp"

namespace lamp::versions
{
	namespace gl
	{
		constexpr u32 major = @GL_MAJOR_VERSION@;
		constexpr u32 minor = @GL_MINOR_VERSION@;
	}
}