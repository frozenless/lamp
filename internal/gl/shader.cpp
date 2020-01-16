#include "shader.hpp"

#include <glad/glad.h>

#ifndef NDEBUG
#include <iostream>
#endif

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

	void Shader::set_source(const std::vector<const char*>& sources)
	{
		assert(!sources.empty());

		glShaderSource(id, sources.size(), sources.data(), nullptr);
	}

	#ifndef NDEBUG
	void Shader::status()
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