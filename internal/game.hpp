#pragma once

#include "window.hpp"

namespace lamp
{
	class Game
	{
	public:
		void run();

	protected:
		Game();

		virtual void init()    = 0;
		virtual void release() = 0;

		virtual void update(f32 delta_time) = 0;
		virtual void draw()                 = 0;

		bool   _show_editor;
		Window _window;
	};
}
