#include "assets.inl"
#include "common.hpp"

#include "utils/config.hpp"

#include "gl/shader.hpp"
#include "gl/program.hpp"
#include "gl/texture.hpp"
#include "gl/mesh.hpp"

#include <stb_image.h>

namespace lamp
{
	gl::shader_ptr Assets::create_shader(const std::string_view& path, const u32 type)
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

	gl::program_ptr Assets::create_program(const gl::shader_ptr& vertex, const gl::shader_ptr& fragment)
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

	gl::mesh_ptr Assets::create_sprite(const v2& size)
	{
		std::vector<f32> vertices =
		{
			size.x,  size.y, 0.0f, 1.0f, 1.0f,
			size.x, -size.y, 0.0f, 1.0f, 0.0f,
		   -size.x, -size.y, 0.0f, 0.0f, 0.0f,
		   -size.x,  size.y, 0.0f, 0.0f, 1.0f
		};

		std::vector<u8> indices =
		{
			0, 3, 1,
			1, 3, 2
		};

		Layout layout;
		layout.add<f32>(3, GL_FLOAT);
		layout.add<f32>(2, GL_FLOAT);

		return create_mesh(vertices, indices, layout, GL_TRIANGLES,  GL_UNSIGNED_BYTE, GL_STATIC_DRAW);
	}

	gl::texture_ptr Assets::create_texture(const std::string_view& path, const bool mipmap, const bool flip)
	{
		auto texture = std::make_shared<gl::Texture>(GL_TEXTURE_2D);

		stbi_set_flip_vertically_on_load(flip);

		unsigned char* data = stbi_load(path.data(), &texture->width,
		                                             &texture->height, &texture->channels, 0);
		assert(data != nullptr);

		glGenTextures(1, &texture->id);

		texture->bind();
		texture->set_data(data);

		stbi_image_free(data);

		if (mipmap) {
			glGenerateMipmap(GL_TEXTURE_2D);

			texture->set_sampler(GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
		} else {
			texture->set_sampler(GL_LINEAR, GL_LINEAR);
		}

		return texture;
	}
}
