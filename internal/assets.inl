#pragma once

#include "gl/assets.hpp"

#include "gl/mesh.hpp"
#include "gl/buffer.inl"

#include <glad/glad.h>

namespace lamp
{
	template<typename T> gl::buffer_ptr Assets::create(const u32 type, const std::vector<T>& info, const u32 usage) noexcept
	{
		auto buffer = std::make_shared<gl::Buffer>(type, usage);

		buffer->create();
		buffer->set_data(info);

		return buffer;
	}

	template<typename T, typename U> gl::mesh_ptr Assets::create(const std::vector<T>& vertices, const std::vector<U>& indices, const Layout& layout, const u32 primitive, const u32 type, const u32 usage)
	{
		auto mesh = std::make_shared<gl::Mesh>();

		mesh->create();
		mesh->bind();

		mesh->vbo = Assets::create(GL_ARRAY_BUFFER,         vertices, usage);
		mesh->ibo = Assets::create(GL_ELEMENT_ARRAY_BUFFER, indices,  usage);

		layout.update();

		mesh->primitive = primitive;

		mesh->count = indices.size();
		mesh->type  = type;

		return mesh;
	}
}