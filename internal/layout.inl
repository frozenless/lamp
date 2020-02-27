#pragma once

#include "layout.hpp"

namespace lamp
{
	template <typename T> void Layout::add(const u32 count, const u32 type) noexcept
	{
		static_assert(std::is_arithmetic<T>::value);
		assert(count != 0);

		_attributes.emplace_back(count, type, _size);
		_size += count * sizeof(T);
	}
}