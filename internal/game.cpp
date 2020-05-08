#include "game.hpp"
#include "engine/random.inl"

#include "gl/renderer.hpp"

#include <GLFW/glfw3.h>

namespace lamp
{
	Timer Game::timer;

	void Game::run(const Window::Config& config, const iv2& size)
	{
		Window::Api::init();

		this->_window.create(config, size);

		this->init_callbacks();

		if (config.context) {

			Window::init();

			gl::Renderer::init();
			gl::Renderer::clear(math::rgb(0.7f));
		}

		Random::seed();

        this->_camera.init(size);
		this->_physics.init();

		this->init();

		this->_ecs.systems.configure();

		auto old_time = Game::timer.elapsed();
		do
		{
			Window::update();

            const auto new_time   = Game::timer.elapsed();
            const auto delta_time = new_time - old_time;

            old_time = new_time;

			if (_running)
			{
                this->_physics.update(delta_time);

                this->update(delta_time);
            }

			this->draw();

			if (config.context)
			{
				this->_window.swap();
			}
		}
		while (!_window.closing());

		gl::Renderer::release();

		this->release();

		Window::Api::release();
	}

    void Game::init_callbacks()
    {
	    auto window = static_cast<GLFWwindow*>(_window);

        glfwSetWindowUserPointer(window, this);

        glfwSetKeyCallback(window, [](GLFWwindow* ptr, const int32_t key, const int32_t, const int32_t action, const int32_t) noexcept {
            static_cast<Game*>(glfwGetWindowUserPointer(ptr))->input(action, key);
        });

        glfwSetMouseButtonCallback(window, [](GLFWwindow* ptr, const int32_t button, const int32_t action, const int32_t) noexcept {
            static_cast<Game*>(glfwGetWindowUserPointer(ptr))->input(action, button);
        });

        glfwSetCursorPosCallback(window, [](GLFWwindow* ptr, const double x, const double y) noexcept {
            static_cast<Game*>(glfwGetWindowUserPointer(ptr))->mouse({ x, y });
        });
    }

	void Game::input(const int32_t action, const int32_t key)
	{
		if (action == GLFW_PRESS) {

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
					if (_show_editor) {
						_physics.debug();
					}
					break;
				}
				case GLFW_KEY_W: {
					_show_wires = !_show_wires;

					gl::Renderer::wire_mode(_show_wires);
					break;
				}
				case GLFW_KEY_P: {
				    _running = !_running;
                    break;
				}
				default:
					break;
			}
		}
	}

    void Game::mouse(const v2& position)
    {
        _mouse = position;
    }

	Physics& Game::physics()
	{
		return _physics;
	}

    Camera& Game::camera()
    {
        return _camera;
    }
}
