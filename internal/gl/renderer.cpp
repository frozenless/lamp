#include "renderer.hpp"

#include <glad/glad.h>

namespace lamp::gl
{
	std::map<uint32_t, bool> Renderer::states;

	void Renderer::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::init()
	{
		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);
	}

	void Renderer::clear(const math::rgb& rgb)
	{
		glClearColor(rgb.r, rgb.g, rgb.b, 1.0f);
	}

	void Renderer::viewport(const iv4& size)
	{
		glViewport(size.x, size.y, size.z, size.w);
	}

	void Renderer::wire_mode(const bool value)
	{
		glPolygonMode(GL_FRONT_AND_BACK, value ? GL_LINE : GL_FILL);
	}

	void Renderer::init_blending()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void Renderer::state(const uint32_t state, const bool value)
	{
		if (states[state] != value) {
			states[state]  = value;

			value ? glEnable(state) : glDisable(state);
		}
	}

	void Renderer::release()
	{
		glUseProgram(0);
	}
}