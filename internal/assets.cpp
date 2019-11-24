#include "assets.hpp"
#include "assets.inl"
#include "config.hpp"

#include <iostream>
#include <numeric>
#include <vector>
#include <array>

namespace lamp
{
	shaderPtr create_shader(const u32 type, const std::string_view& path)
	{
		auto shader = std::make_shared<gl::Shader>();

		std::array<const char*, 2> sources = { versions::glsl.data(), read_file(path).c_str() };

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


	meshPtr create_mesh(const std::vector<f32> &vertices, const std::vector<u32> &indices, const std::vector<gl::Attribute>& attributes, const u32 primitive, const u32 usage)
	{
		auto mesh = std::make_shared<gl::Mesh>();

		glGenVertexArrays(1, &mesh->id);

		mesh->bind();
		mesh->vbo = create_buffer(GL_ARRAY_BUFFER, vertices, usage);
		mesh->ibo = create_buffer(GL_ELEMENT_ARRAY_BUFFER, indices, usage);

		const int vertex_size = std::accumulate(attributes.begin(), attributes.end(), 0, [](const int count, const gl::Attribute& attribute) {
			return count + attribute.count * sizeof(f32);
		});

		for (const gl::Attribute& attribute : attributes)
		{
			glVertexAttribPointer(attribute.index, attribute.count, GL_FLOAT, GL_FALSE, vertex_size, reinterpret_cast<void*>(attribute.offset));
			attribute.enable();
		}

		mesh->primitive = primitive;
		mesh->count     = indices.size();

		return mesh;
	}
}
