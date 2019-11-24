#pragma once

#include "common.hpp"

namespace lamp
{
	shaderPtr  create_shader(u32 type, const std::string_view& path);
	programPtr create_program(const shaderPtr& vertex, const shaderPtr& fragment);
}
