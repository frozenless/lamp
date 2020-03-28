#pragma once

#include "gl/assets.hpp"

#include "gl/mesh.hpp"
#include "gl/buffer.inl"

#include <glad/glad.h>

namespace lamp
{
	template<typename T> gl::buffer_ptr Assets::create(const uint32_t type, const T* data, size_t size, const uint32_t usage) noexcept
	{
		auto buffer = std::make_shared<gl::Buffer>(type, usage);

		buffer->create();
		buffer->set_data(data, size);

		return buffer;
	}

	template<typename T, typename U> gl::mesh_ptr Assets::create(const std::vector<T>& vertices, const std::vector<U>& indices, const gl::Layout& layout, const uint32_t primitive, const uint32_t usage)
	{
		auto mesh = std::make_shared<gl::Mesh>();

		mesh->create();
		mesh->bind();

		static_assert(std::is_integral<U>::value);
		static_assert(std::is_arithmetic<T>::value);

		mesh->vbo = Assets::create(GL_ARRAY_BUFFER,         vertices.data(), vertices.size(), usage);
		mesh->ibo = Assets::create(GL_ELEMENT_ARRAY_BUFFER, indices.data(),  indices.size(),  usage);

		layout.update();

		mesh->primitive = primitive;
		mesh->count     = indices.size();

		if constexpr (std::is_same<U, uint32_t>())
		{
			mesh->type = GL_UNSIGNED_INT;
		}
		else if constexpr (std::is_same<U, uint16_t>())
		{
			mesh->type = GL_UNSIGNED_SHORT;
		}
		else if constexpr (std::is_same<U, uint8_t>())
		{
			mesh->type = GL_UNSIGNED_BYTE;
		}

		return mesh;
	}
}