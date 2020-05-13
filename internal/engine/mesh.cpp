#include "mesh.hpp"

#include <glad/glad.h>

namespace lamp
{
	Mesh::Mesh(const uint32_t primitive)
        : _primitive(primitive)
        , _type(GL_NONE)
		, count(0)
	{
	}

	void Mesh::draw() const noexcept
	{
		glDrawElements(_primitive, count, _type, nullptr);
	}
}