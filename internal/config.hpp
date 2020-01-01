#pragma once

#include "types.hpp"

namespace lamp::versions
{
	constexpr const char glsl[19] = "#version 430 core\n";

	namespace gl
	{
		constexpr u32 major = 4;
		constexpr u32 minor = 3;
	}
}
