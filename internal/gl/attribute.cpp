#include "attribute.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	Attribute::Attribute(int index, int count, int offset)
		: index(index)
		, count(count)
		, offset(offset)
	{
	}

	void Attribute::enable() const noexcept
	{
		glEnableVertexAttribArray(index);
	}
}