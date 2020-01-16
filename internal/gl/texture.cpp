#include "texture.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	Texture::Texture(const u32 target)
		: _target(target)
		, id(0)
	{
	}

	void Texture::bind() const noexcept
	{
		glBindTexture(_target, id);
	}

	u32 Texture::_get_format() const noexcept
	{
		u32 format = GL_NONE;

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
		const int format = _get_format();
		
		glTexImage2D(_target, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	}

	void Texture::set_sampler(const u32 min_filter, const u32 mag_filter) const
	{
		glTexParameteri(_target, GL_TEXTURE_MIN_FILTER, min_filter);
		glTexParameteri(_target, GL_TEXTURE_MAG_FILTER, mag_filter);
	}
}