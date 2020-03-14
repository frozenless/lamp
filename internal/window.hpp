#pragma once

#include "types.hpp"

struct GLFWwindow;

namespace lamp
{
	class Window
	{
	public:
		class Api
		{
		public:
			static void init()    noexcept;
			static void release() noexcept;
		};

		struct Config
		{
			const char* title;

            iv2 size;
            u8  samples;

			bool decorated;
			bool fullscreen;
		};

		Window() noexcept;

		void create(const Config& config) noexcept;

		void close() const noexcept;
		void swap()  const noexcept;

		[[nodiscard]]
		bool closing() const noexcept;

		static void init()   noexcept;
		static void update() noexcept;

		operator GLFWwindow*() const;

	private:
		GLFWwindow* _ptr;
	};
}
