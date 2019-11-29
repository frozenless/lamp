#pragma once

#include "gl/mesh.hpp"
#include "gl/shader.hpp"
#include "gl/program.hpp"
#include "gl/texture.hpp"

#include <string_view>
#include <memory>

namespace lamp
{
	using meshPtr = std::shared_ptr<gl::Mesh>;

	using shaderPtr  = std::shared_ptr<gl::Shader>;
	using programPtr = std::shared_ptr<gl::Program>;
	using texturePtr = std::shared_ptr<gl::Texture>;

	std::string read_file(const std::string_view& path);
}