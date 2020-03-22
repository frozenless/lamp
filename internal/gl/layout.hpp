#pragma once

#include "gl/attribute.hpp"

namespace lamp::gl
{
	class Layout
	{
	public:
		Layout();

		template <typename T> void add(uint32_t count, uint32_t type) noexcept;
			void update() const noexcept;

	private:
		std::vector<attribute> _attributes;
		uint32_t _size;
	};
}