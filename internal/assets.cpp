#include "assets.hpp"
#include "assets.inl"
#include "config.hpp"
#include "layout.hpp"

#include <iostream>
#include <vector>
#include <array>

#include <stb_image.h>

namespace lamp
{
	using Sources = std::array<const char*, 2>;

	shaderPtr create_shader(const std::string_view& path, const u32 type)
	{
		auto shader = std::make_shared<gl::Shader>();

		const std::string& source = read_file(path);
		Sources sources = { versions::glsl, source.c_str() };

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

	meshPtr create_mesh(const vertices& vertices, const indices& indices, const attributes& attributes, const u32 primitive, const u32 usage)
	{
		auto mesh = std::make_shared<gl::Mesh>();

		glGenVertexArrays(1, &mesh->id);

		mesh->bind();
		mesh->vbo = create_buffer(GL_ARRAY_BUFFER, vertices, usage);
		mesh->ibo = create_buffer(GL_ELEMENT_ARRAY_BUFFER, indices, usage);

		const int vertex_size = Layout::calculate_vertex_size(attributes);

		for (const gl::Attribute& attribute : attributes)
		{
			attribute.update(vertex_size);
			attribute.enable();
		}

		mesh->primitive = primitive;
		mesh->count     = indices.size();

		return mesh;
	}

	texturePtr create_texture(const std::string_view& path, const bool mipmap)
	{
		int channels;
		int width, height;
		int format = GL_RGB;

		stbi_set_flip_vertically_on_load(true);

		unsigned char* data = stbi_load(path.data(), &width, &height, &channels, 0);
		assert(data != nullptr);

		if (channels == 4) {
			format = GL_RGBA;
		}

		auto texture = std::make_shared<gl::Texture>();

		glGenTextures(1, &texture->id);
		texture->bind();

		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

		if (mipmap) {
			glGenerateMipmap(GL_TEXTURE_2D);
		}

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);

		return texture;
	}
}
