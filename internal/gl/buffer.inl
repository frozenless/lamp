#include "buffer.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	template <typename T> void Buffer::set_data(const std::vector<T>& info)
	{
		glBufferData(_target, sizeof(T) * info.size(), info.data(), _usage);
	}
}