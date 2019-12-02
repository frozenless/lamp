#pragma once

#include "util.hpp"

namespace lamp::versions
{
	constexpr const char glsl[19] = "@GLSL_VERSION@\n";

	namespace gl
	{
		constexpr u32 major = @GL_MAJOR_VERSION@;
		constexpr u32 minor = @GL_MINOR_VERSION@;
	}
}