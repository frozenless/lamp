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

	void Window::create(const char* title, const iv2& size, const u32 samples, const bool fullscreen) noexcept
	{
		if (samples > 0)
		{
			glfwWindowHint(GLFW_SAMPLES, samples);
		}

		GLFWmonitor* monitor = fullscreen ? glfwGetPrimaryMonitor() : nullptr;

		ptr = glfwCreateWindow(size.x, size.y, title, monitor, nullptr);
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

	void Window::finish() noexcept
	{
		glfwTerminate();
	}

	void Window::init() noexcept
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

	void Window::init_loader() const noexcept
	{
		const bool result = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) != 0;
		assert(result);
	}
}
