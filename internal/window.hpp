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

		static bool init() noexcept;
		static void update() noexcept;
		static void finish() noexcept;

		void swap() const noexcept;

		GLFWwindow* ptr;
	};
}
