#pragma once

#include "window.hpp"

namespace lamp
{
	class Game
	{
	public:
		Game() = default;

		Game(Game&&)      = delete;
		Game(const Game&) = delete;

		Game& operator=(Game&&)      = delete;
		Game& operator=(const Game&) = delete;

		virtual ~Game() = default;

		void run();

	protected:
		virtual void init()    = 0;
		virtual void release() = 0;

		virtual void update(f32 delta_time) = 0;
		virtual void draw()                 = 0;

		Window _window;
	};
}
