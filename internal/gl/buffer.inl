#include "buffer.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	template <typename T> void Buffer::set_data(const std::vector<T>& info) const
	{
		bind();

		if (!info.empty())
		{
			glBufferData(_target, sizeof(T) * info.size(), info.data(), _usage);
		}
	}
}