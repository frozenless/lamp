#include "window.hpp"

namespace lamp
{
	bool Window::create(const std::string_view &title, int width, int height)
	{
		ptr = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);

		return ptr != nullptr;
	}
}
