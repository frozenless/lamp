#include "texture.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	Texture::Texture(const uint32_t target)
		: Object(Type::Texture)
		, _target(target)
		, channels(0)
		, width(0)
		, height(0)
	{
	}

	void Texture::bind() const noexcept
	{
		glBindTexture(_target, _id);
	}

	uint32_t Texture::_format() const noexcept
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

	void Texture::data(const uint8_t* data)
	{
		assert(data  != nullptr);
		assert(width != 0 && height != 0);

		const int32_t format = _format();

		glTexImage2D(_target, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	}

	void Texture::sampler(const uint32_t min_filter, const uint32_t mag_filter) const
	{
		glTexParameteri(_target, GL_TEXTURE_MIN_FILTER, min_filter);
		glTexParameteri(_target, GL_TEXTURE_MAG_FILTER, mag_filter);
	}

	void Texture::create() noexcept
	{
		glCreateTextures(_target, 1, &_id);
	}

	void Texture::release() noexcept
	{
		glDeleteTextures(1, &_id);
	}

	void Texture::activate(uint32_t index)
	{
		glActiveTexture(GL_TEXTURE0 + index);
	}
}