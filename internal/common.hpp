#pragma once

#include "gl/shader.hpp"
#include "gl/program.hpp"

#include <string_view>
#include <memory>

namespace lamp
{
	using shaderPtr  = std::shared_ptr<gl::Shader>;
	using programPtr = std::shared_ptr<gl::Program>;

	std::string read_file(const std::string_view& path);
}