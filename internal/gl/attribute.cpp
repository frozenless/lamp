#include "attribute.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	void Attribute::enable() const noexcept
	{
		glEnableVertexAttribArray(index);
	}
}