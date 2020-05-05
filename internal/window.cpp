#include "window.hpp"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace lamp
{
	void Window::create(const Config& config) noexcept
	{
		if (config.samples != 0)
		{
			glfwWindowHint(GLFW_SAMPLES, config.samples);
		}

		if (!config.decorated)
		{
			glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
		}

		auto monitor = config.fullscreen ? glfwGetPrimaryMonitor() : nullptr;

		_ptr = glfwCreateWindow(config.size.x, config.size.y, config.title, monitor, nullptr);
		assert(_ptr != nullptr);

		glfwMakeContextCurrent(_ptr);
	}

	bool Window::closing() const noexcept
	{
		return glfwWindowShouldClose(_ptr) == GLFW_TRUE;
	}

	void Window::swap() const noexcept
	{
		glfwSwapBuffers(_ptr);
	}

	void Window::update() noexcept
	{
		glfwPollEvents();
	}

	void Window::Api::release() noexcept
	{
		glfwTerminate();
	}

	void Window::Api::init() noexcept
	{
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void Window::close() const noexcept
	{
		glfwSetWindowShouldClose(_ptr, GLFW_TRUE);
	}

	void Window::init() noexcept
	{
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	}

	Window::operator GLFWwindow*() const
	{
		return _ptr;
	}
}
