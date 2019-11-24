#pragma once

#include "util.hpp"
#include <string_view>

namespace lamp::versions
{
	constexpr std::string_view glsl = "@GLSL_VERSION@\n";

	namespace gl
	{
		constexpr u32 major = @GL_MAJOR_VERSION@;
		constexpr u32 minor = @GL_MINOR_VERSION@;
	}
}