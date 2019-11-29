#include "texture.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	void Texture::bind() noexcept
	{
		glBindTexture(GL_TEXTURE_2D, id);
	}
}