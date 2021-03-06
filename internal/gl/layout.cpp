#include "layout.inl"

#include <glad/glad.h>

namespace lamp::gl
{
	void Layout::bind() const noexcept
	{
		uint32_t index = 0;

		for (const auto& attribute : _attributes)
		{
			glVertexAttribPointer(index, attribute.count, attribute.type, GL_FALSE, _size, reinterpret_cast<void*>(attribute.offset));
			glEnableVertexAttribArray(index);

			++index;
		}
	}
}