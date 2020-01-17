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
		for (u32 index = 0; index < _attributes.size(); index++) {
			const auto& attribute = _attributes.at(index);

			glVertexAttribPointer(index, attribute.count, attribute.type, GL_FALSE, _size, (void*)attribute.offset);
			glEnableVertexAttribArray(index);
		}
	}
}