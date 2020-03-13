#pragma once

#include "gl/attribute.hpp"

namespace lamp
{
	class Layout
	{
	public:
		Layout();

		template <typename T> void add(u32 count, u32 type) noexcept;
			void update() const noexcept;

	private:
		std::vector<gl::Attribute> _attributes;
		u32 _size;
	};
}