#include "window.hpp"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "common/config.hpp"

namespace lamp
{
	Window::Window() noexcept
		: ptr(nullptr)
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

		ptr = glfwCreateWindow(config.size.x, config.size.y, config.title, monitor, nullptr);
		assert(ptr != nullptr);

		glfwMakeContextCurrent(ptr);
	}

	bool Window::closing() const noexcept
	{
		return glfwWindowShouldClose(ptr) == GLFW_TRUE;
	}

	void Window::swap() const noexcept
	{
		glfwSwapBuffers(ptr);
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
		glfwSetWindowShouldClose(ptr, GLFW_TRUE);
	}

	void Window::init() noexcept
	{
		const bool result = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) != 0;
		assert(result);
	}
}
