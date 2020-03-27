#include "buffer.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	template <typename T> void Buffer::set_data(const std::vector<T>& buffer) const
	{
		set_data<T>(buffer.data(), buffer.size());
	}

	template <typename T, std::size_t S> void Buffer::set_data(const std::array<T, S>& buffer) const
	{
		set_data<T>(buffer.data(), buffer.size());
	}

	template <typename T> void Buffer::set_data(const T* buffer, const size_t size) const
	{
		bind();

		glBufferData(_target, sizeof(T) * size, buffer, _usage);
	}
}