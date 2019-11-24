#include "assets.hpp"
#include "config.hpp"

#include <glad/glad.h>

#include <iostream>
#include <vector>
#include <array>

namespace lamp
{
	shaderPtr create_shader(const u32 type, const std::string_view& path)
	{
		auto shader = std::make_shared<gl::Shader>();

		const std::string& file = read_file(path);
		const std::string_view& source = file;

		std::array<const char*, 2> sources = { versions::glsl.data(), source.data() };

		shader->id = glCreateShader(type);

		glShaderSource(shader->id, sources.size(), sources.data(), nullptr);
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

	programPtr create_program(const shaderPtr& vertex, const shaderPtr& fragment)
	{
		auto program = std::make_shared<gl::Program>();

		program->id = glCreateProgram();

		program->attach(vertex->id);
		program->attach(fragment->id);

		program->link();

		int success;
		glGetProgramiv(program->id, GL_LINK_STATUS, &success);

		if (!success)
		{
			int length;
			glGetProgramiv(program->id, GL_INFO_LOG_LENGTH, &length);

			std::vector<char> log;
			log.reserve(length);

			glGetProgramInfoLog(program->id, length, nullptr, log.data());

			std::cout << "program linking failed\n" << log.data() << std::endl;
		}

		program->detach(vertex->id);
		program->detach(fragment->id);

		vertex->release();
		fragment->release();

		return program;
	}
}
