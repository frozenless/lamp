#include "assets.inl"
#include "shader.hpp"
#include "program.hpp"
#include "texture.hpp"

#include "common/file.hpp"

#include <stb_image.h>

namespace lamp
{
	gl::shader_ptr Assets::create(const char* path, const uint32_t type)
	{
		const std::string& source = File::read(path);
		auto  shader = std::make_shared<gl::Shader>();

		shader->create(type);

		shader->set_source(source.c_str());
		shader->compile();

		#ifndef NDEBUG
		shader->status();
		#endif

		return shader;
	}

	gl::program_ptr Assets::create(const gl::shader_ptr& vertex, const gl::shader_ptr& fragment)
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

	gl::mesh_ptr Assets::create(const v2& size)
	{
		const std::vector<float> vertices =
		{
			size.x,  size.y, 0.0f, 1.0f, 1.0f,
			size.x, -size.y, 0.0f, 1.0f, 0.0f,
		   -size.x, -size.y, 0.0f, 0.0f, 0.0f,
		   -size.x,  size.y, 0.0f, 0.0f, 1.0f
		};

		const std::vector<uint8_t> indices =
		{
			0, 3, 1,
			1, 3, 2
		};

		gl::Layout layout;
		layout.add<float>(3);
		layout.add<float>(2);

		return create(vertices, indices, layout, GL_TRIANGLES, GL_STATIC_DRAW);
	}

	gl::texture_ptr Assets::create(const char* path, const bool mipmap, const bool flip)
	{
		auto texture = std::make_shared<gl::Texture>(GL_TEXTURE_2D);

		stbi_set_flip_vertically_on_load(flip);

		unsigned char* data = stbi_load(path, &texture->width,
		                                      &texture->height, &texture->channels, 0);
		assert(data != nullptr);

		texture->create();
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
