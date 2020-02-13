#include "mesh.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	Mesh::Mesh()
		: Object(Type::Mesh)
	{
	}

	void Mesh::bind() const noexcept
	{
		glBindVertexArray(id);
	}

	void Mesh::draw() const noexcept
	{
		glDrawElements(primitive, count, type, nullptr);
	}

	void Mesh::create() noexcept
	{
		glGenVertexArrays(1, &id);
	}

	void Mesh::release() noexcept
	{
		glDeleteVertexArrays(1, &id);
	}
}