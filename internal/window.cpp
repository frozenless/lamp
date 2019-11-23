#include "window.hpp"

#include <GLFW/glfw3.h>

namespace lamp
{
	Window::Window() noexcept
		: ptr(nullptr)
	{
	}

	bool Window::create(const std::string_view &title, int width, int height) noexcept
	{
		ptr = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);

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

	void Window::pull_events() noexcept
	{
		glfwPollEvents();
	}

	void Window::finish() noexcept
	{
		glfwTerminate();
	}
}
