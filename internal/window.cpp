#include "window.hpp"
#include "config.hpp"

#include <GLFW/glfw3.h>

namespace lamp
{
	Window::Window() noexcept
		: ptr(nullptr)
	{
	}

	bool Window::create(const std::string_view &title, const iv2& size) noexcept
	{
		ptr = glfwCreateWindow(size.x, size.y, title.data(), nullptr, nullptr);

		return ptr != nullptr;
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

	bool Window::init() noexcept
	{
		const bool result = glfwInit() == GLFW_TRUE;

		if (result)
		{
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, versions::gl::major);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, versions::gl::minor);

			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		}

		return result;
	}
}
