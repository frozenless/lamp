#pragma once

#include <entityx/entityx.h>

#include "engine/components/light.hpp"

#include "physics.hpp"
#include "window.hpp"

namespace lamp
{
	class Game
	{
	public:
		Game();

		Game(Game&&)      = delete;
		Game(const Game&) = delete;

		Game& operator=(Game&&)      = delete;
		Game& operator=(const Game&) = delete;

		virtual ~Game() = default;

		[[nodiscard]] Physics& physics();

		void run(const Window::Config& config);
		void input(int32_t key);

	protected:
		virtual void init()    = 0;
		virtual void release() = 0;

		virtual void update(float) = 0;
		virtual void draw()        = 0;

		bool _show_editor;
		bool _show_wires;

		entityx::EntityX _ecs;

		components::light _light;

		Physics _physics;
		Window  _window;
	};
}
