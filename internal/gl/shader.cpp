#include "shader.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	Shader::Shader()
		: _id(0)
	{
	}

	void Shader::create(const uint32_t type)
	{
        _id = glCreateShader(type);
	}

	void Shader::compile() const noexcept
	{
		glCompileShader(_id);
	}

	void Shader::release() const noexcept
	{
		assert(glIsShader(_id));

		glDeleteShader(_id);
	}

	void Shader::source(const char* source) const
	{
		assert(source != nullptr);

		glShaderSource(_id, 1, &source, nullptr);
	}

    Id Shader::id() const
    {
        return _id;
    }

    #ifndef NDEBUG
	void Shader::status() const
	{
		int32_t success;
		glGetShaderiv(_id, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			int32_t length;
			glGetShaderiv(_id, GL_INFO_LOG_LENGTH, &length);

			std::vector<char> log;
			log.reserve(length);

			glGetShaderInfoLog(_id, length, nullptr, log.data());

			std::cout << "shader compilation failed\n" << log.data() << std::endl;
		}
	}
	#endif
}