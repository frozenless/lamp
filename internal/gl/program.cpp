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
		glUseProgram(_id);
	}

	void Program::attach(const Id shader) const noexcept
	{
		glAttachShader(_id, shader);
	}

	void Program::detach(const Id shader) const noexcept
	{
		glDetachShader(_id, shader);
	}

	void Program::link() const noexcept
	{
		glLinkProgram(_id);
	}

	void Program::release() noexcept
	{
		assert(glIsProgram(_id));

		glDeleteProgram(_id);
	}

	void Program::create() noexcept
	{
        _id = glCreateProgram();
	}

    #ifndef NDEBUG
	void Program::status() const
	{
		int32_t success;
		glGetProgramiv(_id, GL_LINK_STATUS, &success);

		if (!success)
		{
			int32_t length;
			glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &length);

			std::vector<char> log;
			log.reserve(length);

			glGetProgramInfoLog(_id, length, nullptr, log.data());

			std::cout << "program linking failed\n" << log.data() << std::endl;
		}
	}
	#endif
}