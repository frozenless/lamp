#include "game.hpp"
#include "gl/renderer.hpp"

#include "common/random.inl"

#include <GLFW/glfw3.h>

namespace lamp
{
	Game::Game()
		: _show_wires(false)
		, _show_editor(false)
	{
	}

	void Game::run(const Window::Config& config)
	{
		Window::Api::init();

		_window.create(config);

		glfwSetWindowUserPointer(_window, this);

		lamp::Window::init();
		lamp::Random::seed();

		init();

		_ecs.systems.configure();

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

	void Game::toggle_editor()
	{
		_show_editor = !_show_editor;
	}

	void Game::toggle_wires()
	{
		_show_wires = !_show_wires;

		gl::Renderer::set_wire_mode(_show_wires);
	}
}
