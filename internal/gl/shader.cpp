#include "shader.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	void Shader::compile() const noexcept
	{
		glCompileShader(id);
	}
}