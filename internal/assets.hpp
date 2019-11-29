#pragma once

#include "gl/attribute.hpp"
#include "common.hpp"

#include <vector>

namespace lamp
{
	shaderPtr  create_shader(const std::string_view& path, u32 type);
	programPtr create_program(const shaderPtr& vertex, const shaderPtr& fragment);
	texturePtr create_texture(const std::string_view& path, bool mipmap);

	meshPtr create_mesh(const std::vector<f32> &vertices, const std::vector<u32> &indices, const std::vector<gl::Attribute>& attributes, u32 primitive, u32 usage);
}
