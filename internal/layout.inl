#pragma once

#include "gl/layout.hpp"

namespace lamp::gl
{
	template <typename T> void Layout::add(const uint32_t count, const uint32_t type) noexcept
	{
		assert(count != 0);
		static_assert(std::is_arithmetic<T>::value);

		_attributes.emplace_back(count, type, _size);
		_size += count * sizeof(T);
	}
}