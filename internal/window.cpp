#include "window.hpp"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "common/config.hpp"

namespace lamp
{
	Window::Window() noexcept
		: _ptr(nullptr)
	{
	}

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

		GLFWmonitor* monitor = config.fullscreen ? glfwGetPrimaryMonitor() : nullptr;

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
		const bool result = glfwInit() == GLFW_TRUE;
		assert(result);

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, versions::gl::major);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, versions::gl::minor);

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void Window::close() const noexcept
	{
		glfwSetWindowShouldClose(_ptr, GLFW_TRUE);
	}

	void Window::init() noexcept
	{
		const bool result = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) != 0;
		assert(result);
	}

	Window::operator GLFWwindow*() const
	{
		return _ptr;
	}
}
