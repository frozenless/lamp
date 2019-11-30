#include "attribute.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	Attribute::Attribute(int index, int count, int offset)
		: _index(index)
		, _offset(offset)
		, count(count)
	{
	}

	void Attribute::update(const int vertex_size) const noexcept
	{
		glVertexAttribPointer(_index, count, GL_FLOAT, GL_FALSE, vertex_size, reinterpret_cast<void*>(_offset));
	}

	void Attribute::enable() const noexcept
	{
		glEnableVertexAttribArray(_index);
	}
}