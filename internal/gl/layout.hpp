#pragma once

#include "gl/attribute.hpp"

namespace lamp::gl
{
	class Layout
	{
	public:
		template <typename T> void add(uint32_t count) noexcept;
			void bind() const noexcept;

	private:
		std::vector<attribute> _attributes;

		uint32_t _size = 0;
	};
}