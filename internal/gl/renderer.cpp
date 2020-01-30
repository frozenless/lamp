#include "renderer.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	std::map<Renderer::Bindings, handle> Renderer::_bindings;

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

	void Renderer::bind(const Bindings type, const Object& object)
	{
		if (_bindings[type] != object.id) {
			_bindings[type]  = object.id;

			object.bind();
		}
	}
}