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
		for (const auto& attribute : _attributes)
		{
			glVertexAttribPointer(attribute.index, attribute.count, attribute.type, GL_FALSE, _size, (void*)attribute.offset);
			glEnableVertexAttribArray(attribute.index);
		}
	}
}