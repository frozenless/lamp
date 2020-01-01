#pragma once

#include "types.hpp"

struct GLFWwindow;

namespace lamp
{
	class Window
	{
	public:
		Window() noexcept;

		void create(const char* title, const iv2& size, u32 samples = 0, bool fullscreen = false) noexcept;
		void close() const noexcept;

		bool closing() const noexcept;

		static void init() noexcept;
		static void update() noexcept;
		static void finish() noexcept;

		void init_loader() const noexcept;
		void swap() const noexcept;

		GLFWwindow* ptr;
	};
}
