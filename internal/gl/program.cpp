#include "program.hpp"

#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>

namespace lamp::gl
{
	void Program::use() const noexcept
	{
		glUseProgram(id);
	}

	void Program::uniform(const int location, const m4& mat)
	{
		assert(location != -1);

		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
	}

	void Program::uniform(const int location, const v3& vec)
	{
		assert(location != -1);

		glUniform3fv(location, 1, glm::value_ptr(vec));
	}

	void Program::uniform(const int location, const f32 value) noexcept
	{
		assert(location != -1);

		glUniform1f(location, value);
	}

	void Program::attach(const u32 shader) const noexcept
	{
		glAttachShader(id, shader);
	}

	void Program::detach(const u32 shader) const noexcept
	{
		glDetachShader(id, shader);
	}

	void Program::link() const noexcept
	{
		glLinkProgram(id);
	}
}