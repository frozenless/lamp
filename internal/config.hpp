#pragma once

#include "util.hpp"
#include <string_view>

namespace lamp::versions
{
	constexpr std::string_view glsl = "#version 430 core\n";

	namespace gl
	{
		constexpr u32 major = 4;
		constexpr u32 minor = 3;
	}
}
