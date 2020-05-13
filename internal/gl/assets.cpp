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
		assert(path != nullptr);

		auto shader = std::make_shared<gl::Shader>();

		shader->create(type);
		shader->source(File::read(path).c_str());
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

	mesh_ptr Assets::create(const v2& size)
	{
        const std::array<v2, 8> vertices =
        {
            v2( size.x,  size.y), v2(1.0f, 1.0f),
            v2( size.x, -size.y), v2(1.0f, 0.0f),
            v2(-size.x, -size.y), v2(0.0f, 0.0f),
            v2(-size.x,  size.y), v2(0.0f, 1.0f)
        };

        const std::array<uint8_t, 6> indices =
        {
            0, 3, 1,
            1, 3, 2
        };

        gl::Layout layout;
        layout.add<float>(2);
        layout.add<float>(2);

        return create(vertices, indices, layout, GL_TRIANGLES, GL_STATIC_DRAW);
	}

	gl::texture_ptr Assets::create(const char* path, const bool mipmap, const bool flip)
	{
		assert(path != nullptr);

		auto texture = std::make_shared<gl::Texture>(GL_TEXTURE_2D);
		stbi_set_flip_vertically_on_load(flip);

		auto data = stbi_load(path, &texture->width,
                                    &texture->height, &texture->channels, 0);
		texture->create();
		texture->bind();
		texture->data(data);

		stbi_image_free(data);

		if (mipmap)
		{
			glGenerateMipmap(GL_TEXTURE_2D);

			texture->sampler(GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
		}
		else
		{
			texture->sampler(GL_LINEAR, GL_LINEAR);
		}

		return texture;
	}

	gl::buffer_ptr Assets::create(const uint32_t type, const uint32_t usage, const uint32_t index)
	{
		auto buffer = std::make_shared<gl::Buffer>(type, usage);

		buffer->create();
		buffer->bind(index);

		return buffer;
	}

    mesh_ptr Assets::create(const gl::Layout& layout, const uint32_t primitive, const uint32_t usage) {

        return create<std::any, uint32_t>(std::make_pair(nullptr, 0),
                                          std::make_pair(nullptr, 0), layout, primitive, usage);
    }
}
