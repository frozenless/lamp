#include "buffer.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	template <typename T> void Buffer::data(const std::vector<T>& buffer) const noexcept
	{
		this->data<T>({ buffer.data(), buffer.size() });
	}

	template <typename T, std::size_t S> void Buffer::data(const std::array<T, S>& buffer) const noexcept
	{
		this->data<T>({ buffer.data(), buffer.size() });
	}

	template <typename T> void Buffer::data(const std::pair<const T*, size_t>& buffer) const noexcept
	{
		this->bind();

		if (buffer.second != 0) {
            glBufferData(_target, sizeof(T) * buffer.second, buffer.first, _usage);
        }
	}
}