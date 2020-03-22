#include "shader.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	Shader::Shader()
		: id(0)
	{
	}

	void Shader::create(const u32 type)
	{
		id = glCreateShader(type);
	}

	void Shader::compile() const noexcept
	{
		glCompileShader(id);
	}

	void Shader::release() const noexcept
	{
		assert(glIsShader(id));

		glDeleteShader(id);
	}

	void Shader::set_source(const char* source) const
	{
		glShaderSource(id, 1, &source, nullptr);
	}

	#ifndef NDEBUG
	void Shader::status() const
	{
		int success;
		glGetShaderiv(id, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

			std::vector<char> log;
			log.reserve(length);

			glGetShaderInfoLog(id, length, nullptr, log.data());

			std::cout << "shader compilation failed\n" << log.data() << std::endl;
		}
	}
	#endif
}