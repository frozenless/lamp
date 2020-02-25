#include "game.hpp"

#include <GLFW/glfw3.h>

namespace lamp
{
	void Game::run(const Window::Config& config)
	{
		Window::Api::init();

		if (config.decorated)
		{
			glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
		}

		_window.create(config.title, config.size, config.samples);

		lamp::Window::init();

		init();

		f64 old_time = glfwGetTime();

		do
		{
			const  f64 new_time   = glfwGetTime();
			const auto delta_time = static_cast<f32>(new_time - old_time);
			old_time = new_time;

			Window::update();

			update(delta_time);
			draw();

			_window.swap();
		}
		while (!_window.closing());

		release();

		Window::Api::release();
	}

	const Window& Game::window() const
	{
		return _window;
	}

	const Light& Game::light() const
	{
		return _light;
	}

	Physics& Game::physics()
	{
		return _physics;
	}
}
