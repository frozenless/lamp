#pragma once

#include <string_view>

namespace lamp::versions
{
	constexpr std::string_view glsl = "#version 430 core\n";

	namespace gl
	{
		constexpr unsigned int major = 4;
		constexpr unsigned int minor = 3;
	}
}
