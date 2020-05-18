#pragma once

#include "physics.hpp"
#include "window.hpp"

#include "common/timer.hpp"

#include <entityx/entityx.h>

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

        entityx::EntityX ecs;
        static   Timer timer;

        Physics physics;

    private:
        void init_debug()     noexcept;
        void init_callbacks() noexcept;
        void init_systems()   noexcept;

        bool _running = true;

    protected:
        virtual void init()    = 0;
        virtual void release() = 0;

        virtual void update(float) = 0;
        virtual void draw()        = 0;

        Window _window;
        v2     _mouse;
    };
}
