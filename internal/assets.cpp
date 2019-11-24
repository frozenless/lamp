#include "assets.hpp"
#include "config.hpp"

#include <glad/glad.h>

#include <iostream>
#include <vector>

namespace lamp
{
	shaderPtr create_shader(unsigned int type, const std::string_view& path)
	{
		auto shader = std::make_shared<gl::Shader>();

		const std::string& file = read_file(path);
		const std::string_view& source = file;

		// Todo try to use std::array?
		const char* sources[2] = { versions::glsl.data(), source.data() };

		shader->id = glCreateShader(type);

		glShaderSource(shader->id, 2, sources, nullptr);
		shader->compile();

		int success;
		glGetShaderiv(shader->id, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			int length;
			glGetShaderiv(shader->id, GL_INFO_LOG_LENGTH, &length);

			std::vector<char> log;
			log.reserve(length);

			glGetShaderInfoLog(shader->id, length, nullptr, log.data());

			std::cout << "shader compilation failed\n" << log.data() << std::endl;
		}

		return shader;
	}
}
