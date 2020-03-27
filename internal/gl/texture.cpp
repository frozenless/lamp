#include "texture.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	Texture::Texture(const uint32_t target)
		: Object(Type::Texture)
		, _target(target)
	{
	}

	void Texture::bind() const noexcept
	{
		glBindTexture(_target, id);
	}

	uint32_t Texture::_get_format() const noexcept
	{
		uint32_t format = GL_NONE;

		switch (channels)
		{
			case 4: format = GL_RGBA; break;
			case 3: format = GL_RGB;  break;
		}

		assert(format != GL_NONE);
		return format;
	}

	void Texture::set_data(const unsigned char* data)
	{
		const int32_t format = _get_format();
		
		glTexImage2D(_target, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	}

	void Texture::set_sampler(const uint32_t min_filter, const uint32_t mag_filter) const
	{
		glTexParameteri(_target, GL_TEXTURE_MIN_FILTER, min_filter);
		glTexParameteri(_target, GL_TEXTURE_MAG_FILTER, mag_filter);
	}

	void Texture::create() noexcept
	{
		glCreateTextures(_target, 1, &id);
	}

	void Texture::release() noexcept
	{
		glDeleteTextures(1, &id);
	}
}