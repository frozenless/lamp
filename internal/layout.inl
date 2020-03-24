#pragma once

#include "gl/layout.hpp"

namespace lamp::gl
{
	template <typename T> void Layout::add(const uint32_t count) noexcept
	{
		uint32_t type  = GL_NONE;

		if (typeid(T) == typeid(float))
		{
			type = GL_FLOAT;
		}

		assert(count != 0);
		assert(type  != GL_NONE);

		static_assert(std::is_arithmetic<T>::value);

		_attributes.emplace_back(count, type, _size);
		_size += count * sizeof(T);
	}
}