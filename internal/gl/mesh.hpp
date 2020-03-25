#pragma once

#include "object.hpp"

namespace lamp::gl
{
	struct Mesh : public Object
	{
		Mesh();

		void create()  noexcept final;
		void release() noexcept final;

		void bind() const noexcept final;
		void draw() const noexcept;

		std::size_t count;

		buffer_ptr vbo;
		buffer_ptr ibo;

		uint32_t primitive;
		uint32_t type;
	};
}
