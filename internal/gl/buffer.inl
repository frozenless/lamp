#include "buffer.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	template <typename T> void Buffer::set_data(const std::vector<T>& buffer) const
	{
		bind();

		if (!buffer.empty()) {
			glBufferData(_target, sizeof(T) * buffer.size(),
					                          buffer.data(), _usage);
		}
	}
}