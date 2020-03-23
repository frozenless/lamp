#include "game.hpp"
#include "engine/random.inl"

#include "gl/renderer.hpp"

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

		lamp::gl::Renderer::init();
		lamp::gl::Renderer::set_clear_color(lamp::rgb(0.7f));

		_physics.init();

		this->init();

		_ecs.systems.configure();

		double old_time = glfwGetTime();
		do
		{
			const double new_time = glfwGetTime();
			const auto delta_time = static_cast<float>(new_time - old_time);
			old_time = new_time;

			Window::update();

			this->update(delta_time);
			this->draw();

			_window.swap();
		}
		while (!_window.closing());

		this->release();

		Window::Api::release();
	}

	void Game::input(const int32_t key)
	{
		switch (key) {
			case GLFW_KEY_ESCAPE: {
				_window.close();
				break;
			}
			case GLFW_KEY_E: {
				_show_editor = !_show_editor;
				break;
			}
			case GLFW_KEY_D: {
				_physics.debug();
				break;
			}
			case GLFW_KEY_W: {
				_show_wires = !_show_wires;

				gl::Renderer::set_wire_mode(_show_wires);
				break;
			}
			default:
				break;
		}
	}

	Physics& Game::physics()
	{
		return _physics;
	}
}
