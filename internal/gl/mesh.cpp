#include "mesh.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	void Mesh::bind() const noexcept
	{
		glBindVertexArray(id);
	}

	void Mesh::draw() const noexcept
	{
		glDrawElements(primitive, count, type, nullptr);
	}
}