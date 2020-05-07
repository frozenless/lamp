#pragma once

#include <entityx/entityx.h>

#include "engine/components/light.hpp"

#include "common/timer.hpp"
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

		virtual void input(int32_t action, int32_t key);

		void run(const Window::Config& config);

		[[nodiscard]] Physics& physics();

		static Timer timer;

	protected:
		virtual void init()    = 0;
		virtual void release() = 0;

		virtual void update(float) = 0;
		virtual void draw()        = 0;

		bool _show_editor = false;
		bool _show_wires  = false;
		bool _running     = true;

		components::light _light;
        entityx::EntityX  _ecs;

		Physics _physics;
		Window  _window;
	};
}
