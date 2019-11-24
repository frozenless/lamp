#pragma once

#include "common.hpp"

namespace lamp
{
	shaderPtr create_shader(unsigned int type, const std::string_view& path);
}
