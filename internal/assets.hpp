#pragma once

#include "common.hpp"
#include "gl/attribute.hpp"

#include <vector>

namespace lamp
{
	shaderPtr  create_shader(u32 type, const std::string_view& path);
	programPtr create_program(const shaderPtr& vertex, const shaderPtr& fragment);

	meshPtr create_mesh(const std::vector<f32> &vertices, const std::vector<u32> &indices, const std::vector<gl::Attribute>& attributes, u32 primitive, u32 usage);
}
