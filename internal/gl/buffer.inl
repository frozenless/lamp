#include "buffer.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	template <typename T> void Buffer::data(const std::vector<T>& buffer) const noexcept
	{
		data<T>({ buffer.data(), buffer.size() });
	}

	template <typename T, std::size_t S> void Buffer::data(const std::array<T, S>& buffer) const noexcept
	{
		data<T>({ buffer.data(), buffer.size() });
	}

	template <typename T> void Buffer::data(const std::pair<const T*, size_t>& buffer) const noexcept
	{
		if (buffer.second != 0)
		{
            glNamedBufferData(_id, sizeof(T) * buffer.second, buffer.first, _usage);
        }
	}

    template <typename T> void Buffer::sub_data(const std::pair<const T*, size_t>& buffer, const int32_t offset)
    {
        if (buffer.second != 0)
        {
            glNamedBufferSubData(_id, offset, sizeof(T) * buffer.second, buffer.first);
        }
    }
}