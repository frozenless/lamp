#pragma once

#include "object.hpp"

namespace lamp::gl
{
	struct Mesh : public Object
	{
		void bind() const noexcept final;
		void draw() const noexcept;

		std::size_t count;

		buffer_ptr vbo;
		buffer_ptr ibo;

		u32 primitive;
		u32 type;
	};
}
