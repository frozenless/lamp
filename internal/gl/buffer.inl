#include "buffer.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	template <typename T> void Buffer::set_data(const std::vector<T>& buffer) const
	{
		bind();

		if (!buffer.empty())
		{
			_set_data<T>(buffer.data(), buffer.size());
		}
	}

	template <typename T, std::size_t S> void Buffer::set_data(const std::array<T, S>& buffer) const
	{
		bind();

		if (!buffer.empy()) {
			_set_data<T>(buffer.data(), buffer.size());
		}
	}

	template <typename T> void Buffer::_set_data(const void* buffer, const uint32_t size) const
	{
		glBufferData(_target, sizeof(T) * size, buffer, _usage);
	}
}