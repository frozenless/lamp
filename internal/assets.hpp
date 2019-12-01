#pragma once

#include "gl/attribute.hpp"
#include "common.hpp"

#include <vector>

namespace lamp
{
	using vertices = std::vector<f32>;
	using indices  = std::vector<u32>;

	using attributes = std::vector<gl::Attribute>;

	shaderPtr  create_shader(const std::string_view& path, u32 type);
	texturePtr create_texture(const std::string_view& path, bool mipmap);
	programPtr create_program(const shaderPtr& vertex, const shaderPtr& fragment);

	meshPtr create_mesh(const vertices& vertices, const indices& indices, const attributes& attributes, u32 primitive, u32 usage);
}
