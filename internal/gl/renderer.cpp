#include "renderer.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	void Renderer::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::init()
	{
		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);
	}

	void Renderer::set_clear_color(const rgb& color)
	{
		glClearColor(color.r, color.g, color.b, 1.0f);
	}

	void Renderer::set_viewport(const iv4& size)
	{
		glViewport(size.x, size.y, size.z, size.w);
	}
}