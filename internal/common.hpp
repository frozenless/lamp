#pragma once

#include "gl/shader.hpp"

#include <string_view>
#include <memory>

namespace lamp
{
	using shaderPtr = std::shared_ptr<gl::Shader>;

	std::string read_file(const std::string_view& path);
}