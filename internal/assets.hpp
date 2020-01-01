#pragma once

#include "gl/attribute.hpp"
#include "types.hpp"

#include <string_view>
#include <vector>

namespace lamp
{
	using vertices = std::vector<f32>;
	using indices  = std::vector<u32>;

	using attributes = std::vector<gl::Attribute>;

	gl::shader_ptr  create_shader(const std::string_view& path, u32 type);
	gl::texture_ptr create_texture(const std::string_view& path, bool mipmap);
	gl::program_ptr create_program(const gl::shader_ptr& vertex, const gl::shader_ptr& fragment);

	gl::mesh_ptr create_mesh(const vertices& vertices, const indices& indices, const attributes& attributes, u32 primitive, u32 usage);
}
