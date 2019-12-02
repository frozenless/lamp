#pragma once

#include "util.hpp"

namespace lamp::gl
{
	struct Mesh
	{
		void bind() const noexcept;
		void draw() const noexcept;

		u32 id;

		u32 vbo;
		u32 ibo;

		u32 primitive;

		std::size_t count;
	};
}
