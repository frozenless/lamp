#pragma

#include <string_view>

struct GLFWwindow;

namespace lamp
{
	class Window
	{
	public:
		Window() noexcept;

		bool create(const std::string_view& title, int width, int height) noexcept;
		bool closing() const noexcept;

		static void pull_events() noexcept;
		static void finish() noexcept;

		void swap() const noexcept;

		GLFWwindow* ptr;
	};
}
