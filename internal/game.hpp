#pragma once

#include "engine/light.hpp"

#include "physics.hpp"
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

		[[nodiscard]] const Window&  window() const;
		[[nodiscard]] const Physics& physics();
		[[nodiscard]] const Light&   light();

		void run();

	protected:
		virtual void init()    = 0;
		virtual void release() = 0;

		virtual void update(f32 delta_time) = 0;
		virtual void draw()                 = 0;

		Window _window;

		Physics _physics;
		Light   _light;
	};
}
