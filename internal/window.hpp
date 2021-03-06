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
			Api() = delete;

			static void init()    noexcept;
			static void release() noexcept;
		};

		struct Config
		{
			const char* title;

            iv2     size;
            uint8_t samples;

			bool decorated;
			bool fullscreen;

			bool context;
		};

		Window() noexcept;

		explicit operator GLFWwindow*() const;

		void create(const Config& config) noexcept;

		void close() const noexcept;
		void swap()  const noexcept;

		[[nodiscard]]
		bool closing() const noexcept;

		static void init()   noexcept;
		static void update() noexcept;

	private:
		GLFWwindow* _ptr;
	};
}
