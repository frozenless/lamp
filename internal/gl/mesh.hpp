#pragma once

#include "types.hpp"

namespace lamp::gl
{
	struct Mesh
	{
		void bind() const noexcept;
		void draw() const noexcept;

		std::size_t count;
		u32 primitive;

		handle vbo;
		handle ibo;

		handle id;
	};
}
