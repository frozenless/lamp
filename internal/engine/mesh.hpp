#pragma once

#include "gl/vertex/array.hpp"

namespace lamp
{
	struct Mesh
	{
		explicit Mesh(uint32_t primitive);

		void draw() const noexcept;

		template <typename U> constexpr void type();

		gl::vertex::array_ptr vao;

		gl::buffer_ptr vbo;
        gl::buffer_ptr ibo;

        std::size_t count;

	private:
        uint32_t _primitive;
		uint32_t _type;
	};
}
