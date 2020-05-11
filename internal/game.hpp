#pragma once

#include <entityx/entityx.h>

#include "engine/components/light.hpp"
#include "engine/camera.hpp"

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

		void run(const Window::Config& config, const iv2& size);
        void mouse(const v2& position);

		[[nodiscard]] Physics& physics();
		[[nodiscard]] Camera&  camera();

		static Timer timer;

    private:
        void init_debug()     noexcept;
        void init_callbacks() noexcept;

        bool _wire_mode = false;
        bool _running   = true;

	protected:
		virtual void init()    = 0;
		virtual void release() = 0;

		virtual void update(float) = 0;
		virtual void draw()        = 0;

        bool _show_editor = false;

		components::light _light;
        entityx::EntityX  _ecs;

		Physics _physics;
		Window  _window;

        Camera _camera;
        v2     _mouse;
	};
}
