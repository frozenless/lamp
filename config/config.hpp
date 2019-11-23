#pragma once

#include <string_view>

namespace lamp::versions
{
	constexpr std::string_view glsl = "@GLSL_VERSION@\n";

	namespace gl
	{
		constexpr unsigned int major = @GL_MAJOR_VERSION@;
		constexpr unsigned int minor = @GL_MINOR_VERSION@;
	}
}