#pragma

#include <GLFW/glfw3.h>
#include <string_view>

namespace lamp
{
	class Window
	{
		bool create(const std::string_view& title, int width, int height);

		GLFWwindow* ptr;
	};
}
