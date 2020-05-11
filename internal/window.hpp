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
            uint8_t samples;

			bool decorated;
			bool fullscreen;
			bool context;
		};

		void create(const Config& config, const iv2& size) noexcept;

		void close() const noexcept;
		void swap()  const noexcept;

		[[nodiscard]]
		bool closing() const noexcept;

		static void init()   noexcept;
		static void update() noexcept;

        explicit operator GLFWwindow*() const;

	private:
		GLFWwindow* _ptr = nullptr;
	};
}
