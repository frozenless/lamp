#include "mesh.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	Mesh::Mesh(const uint32_t primitive)
		: Object(Type::Mesh)
        , _primitive(primitive)
        , _type(GL_NONE)
		, count(0)
	{
	}

	void Mesh::bind() const noexcept
	{
		glBindVertexArray(id);
	}

	void Mesh::draw() const noexcept
	{
		glDrawElements(_primitive, count, _type, nullptr);
	}

	void Mesh::create() noexcept
	{
		glCreateVertexArrays(1, &id);
	}

	void Mesh::release() noexcept
	{
		glDeleteVertexArrays(1, &id);
	}
}