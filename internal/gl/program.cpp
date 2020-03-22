#include "program.hpp"

#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>

namespace lamp::gl
{
	Program::Program()
		: Object(Type::Shader)
	{
	}

	void Program::bind() const noexcept
	{
		glUseProgram(id);
	}

	void Program::uniform(const int32_t location, const m4& mat)
	{
		assert(location != -1);

		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
	}

	void Program::uniform(const int32_t location, const v3& vec)
	{
		assert(location != -1);

		glUniform3fv(location, 1, glm::value_ptr(vec));
	}

	void Program::uniform(const int32_t location, const float value) noexcept
	{
		assert(location != -1);

		glUniform1f(location, value);
	}

	void Program::attach(const ID shader) const noexcept
	{
		glAttachShader(id, shader);
	}

	void Program::detach(const ID shader) const noexcept
	{
		glDetachShader(id, shader);
	}

	void Program::link() const noexcept
	{
		glLinkProgram(id);
	}

	void Program::release() noexcept
	{
		assert(glIsProgram(id));

		glDeleteProgram(id);
	}

	void Program::create() noexcept
	{
		id = glCreateProgram();
	}

    #ifndef NDEBUG
	void Program::status() const
	{
		int32_t success;
		glGetProgramiv(id, GL_LINK_STATUS, &success);

		if (!success)
		{
			int32_t length;
			glGetProgramiv(id, GL_INFO_LOG_LENGTH, &length);

			std::vector<char> log;
			log.reserve(length);

			glGetProgramInfoLog(id, length, nullptr, log.data());

			std::cout << "program linking failed\n" << log.data() << std::endl;
		}
	}
	#endif
}