#include "renderer.hpp"

#include "gl/program.hpp"
#include <glad/glad.h>

namespace lamp::gl
{
	handle Renderer::_shader = 0;

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

	void Renderer::set_wire_mode(const bool value)
	{
		glPolygonMode(GL_FRONT_AND_BACK, value ? GL_LINE : GL_FILL);
	}

	void Renderer::set_shader(const program_ptr& shader)
	{
		if (_shader == shader->id)
		    return;

		_shader = shader->id;
	              shader->use();
	}

	void Renderer::init_blending()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void Renderer::enable(const u32 value)
	{
		glEnable(value);
	}

	void Renderer::disable(const u32 value)
	{
		glDisable(value);
	}

	bool Renderer::bind(const Bindings type, const handle id)
	{
		if (_bindings[type] != id) {
			_bindings[type]  = id;
			return true;
		}   return false;
	}
}