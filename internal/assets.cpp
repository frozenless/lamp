#include "assets.hpp"
#include "assets.inl"
#include "config.hpp"
#include "layout.hpp"
#include "common.hpp"

#include "gl/shader.hpp"
#include "gl/program.hpp"
#include "gl/mesh.hpp"
#include "gl/texture.hpp"

#include <stb_image.h>
#include <iostream>

#ifndef NDEBUG
#include <vector>
#endif

namespace lamp
{
	gl::shader_ptr create_shader(const std::string_view& path, const u32 type)
	{
		const std::string& source = read_file(path.data());
		auto  shader = std::make_shared<gl::Shader>();

		shader->create(type);

		shader->set_source({ versions::glsl, source.c_str() });
		shader->compile();

		#ifndef NDEBUG
		shader->status();
		#endif

		return shader;
	}

	gl::program_ptr create_program(const gl::shader_ptr& vertex, const gl::shader_ptr& fragment)
	{
		auto program = std::make_shared<gl::Program>();

		program->create();

		program->attach(vertex->id);
		program->attach(fragment->id);

		program->link();

		#ifndef NDEBUG
		program->status();
		#endif

		program->detach(vertex->id);
		program->detach(fragment->id);

		vertex->release();
		fragment->release();

		return program;
	}

	gl::mesh_ptr create_mesh(const vertices& vertices, const indices& indices, const attributes& attributes, const u32 primitive, const u32 usage)
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

	gl::texture_ptr create_texture(const std::string_view& path, const bool mipmap)
	{
		auto texture = std::make_shared<gl::Texture>(GL_TEXTURE_2D);

		stbi_set_flip_vertically_on_load(true);

		unsigned char* data = stbi_load(path.data(), &texture->width,
				                                     &texture->height, &texture->channels, 0);
		assert(data != nullptr);

		glGenTextures(1, &texture->id);

		texture->bind();
		texture->set_data(data);

		stbi_image_free(data);

		if (mipmap) {
			glGenerateMipmap(GL_TEXTURE_2D);
		}

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		return texture;
	}
}
