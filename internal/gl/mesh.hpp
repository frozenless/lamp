#pragma once

#include "object.hpp"

namespace lamp::gl
{
	class Mesh : public Object
	{
	public:
		explicit Mesh(uint32_t primitive);

		~Mesh() = default;

		void create()  noexcept final;
		void release() noexcept final;

		void bind() const noexcept final;
		void draw() const noexcept;

		template <typename U> constexpr void type();

		std::size_t count;

		buffer_ptr vbo;
		buffer_ptr ibo;

	private:
        uint32_t _primitive;
		uint32_t _type;
	};
}
