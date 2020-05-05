#include "program.hpp"

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

		assert(glIsProgram(id) == GL_FALSE);
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