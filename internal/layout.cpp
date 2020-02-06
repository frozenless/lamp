#include "layout.inl"

#include <glad/glad.h>

namespace lamp
{
	Layout::Layout()
		: _size(0)
	{
	}

	void Layout::update() const noexcept
	{
		u32 index = 0;

		for (const auto& attribute : _attributes) {
			glVertexAttribPointer(index, attribute.count, attribute.type, GL_FALSE, _size, (void*)attribute.offset);
			glEnableVertexAttribArray(index++);
		}
	}
}