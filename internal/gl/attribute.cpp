#include "attribute.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	void Attribute::update(const int vertex_size) const noexcept
	{
		glVertexAttribPointer(index, count, GL_FLOAT, GL_FALSE, vertex_size, reinterpret_cast<void*>(offset));
	}

	void Attribute::enable() const noexcept
	{
		glEnableVertexAttribArray(index);
	}
}