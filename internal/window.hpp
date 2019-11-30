#pragma

#include "util.hpp"
#include <string_view>

struct GLFWwindow;

namespace lamp
{
	class Window
	{
	public:
		Window() noexcept;

		bool create(const std::string_view& title, const iv2& size, u32 samples = 0) noexcept;
		bool closing() const noexcept;

		static bool init() noexcept;
		static void update() noexcept;
		static void finish() noexcept;

		void swap() const noexcept;

		GLFWwindow* ptr;
	};
}
