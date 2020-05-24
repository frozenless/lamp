#include "game.hpp"
#include "assets.inl"

#include "common/random.hpp"

#include "engine/systems/camera.hpp"
#include "engine/systems/renderer.hpp"
#include "engine/systems/physics.hpp"
#include "engine/systems/light.hpp"
#include "engine/systems/editor.hpp"

#include "engine/components/transform.hpp"
#include "engine/components/renderer.hpp"
#include "engine/components/camera.hpp"

#include "physics/renderer.hpp"
#include "gl/renderer.hpp"

#include <GLFW/glfw3.h>

namespace lamp
{
    Timer Game::time;

    void Game::run(const Window::Config& config, const iv2& size)
    {
        Window::Api::init();

        this->_window.create(config, size);

        init_callbacks();

        if (config.context) {

            Window::init();

            gl::Renderer::init();
            gl::Renderer::clear({ 0.7f, 0.7f, 0.7f });
        }

        Random::seed();

        physics.init();

        init_systems();
        init_debug();

        init();

        auto old_time = Game::time.elapsed();
        do
        {
            Window::update();

            const auto new_time   = Game::time.elapsed();
            const auto delta_time = new_time - old_time;

            old_time = new_time;

            if (_running)
            {
                physics.update(delta_time);

                update_systems(delta_time);
                update(delta_time);
            }

            draw_systems();
            draw();

            if (config.context)
            {
                this->_window.swap();
            }
        }
        while (!_window.closing());

        release();

        Window::Api::release();
    }

    void Game::init_debug() noexcept
    {
        gl::Layout layout;
        layout.add<float>(3);
        layout.add<float>(3);

        auto vertex   = Assets::create("shaders/glsl/debug.vert", GL_VERTEX_SHADER);
        auto fragment = Assets::create("shaders/glsl/debug.frag", GL_FRAGMENT_SHADER);

        auto debug    = ecs.entities.create();
        auto renderer = debug.assign<components::renderer>();

        debug.assign<components::transform>()->world = glm::identity<m4>();

        renderer->mesh     = Assets::create(layout, GL_LINES, GL_DYNAMIC_DRAW);
        renderer->shader   = Assets::create(vertex, fragment);
        renderer->material = nullptr;

        physics.renderer(new physics::Renderer(renderer->mesh, btIDebugDraw::DBG_DrawWireframe));
    }

    void Game::init_callbacks() noexcept
    {
        auto window = static_cast<GLFWwindow*>(_window);

        glfwSetKeyCallback(window, [](GLFWwindow* ptr, const int32_t key, const int32_t, const int32_t action, const int32_t) noexcept {
            static_cast<Game*>(glfwGetWindowUserPointer(ptr))->input(action, key);
        });

        glfwSetMouseButtonCallback(window, [](GLFWwindow* ptr, const int32_t button, const int32_t action, const int32_t) noexcept {
            static_cast<Game*>(glfwGetWindowUserPointer(ptr))->input(action, button);
        });

        glfwSetCursorPosCallback(window, [](GLFWwindow* ptr, const double x, const double y) noexcept {
            static_cast<Game*>(glfwGetWindowUserPointer(ptr))->mouse({ x, y });
        });

        glfwSetScrollCallback(window, [](GLFWwindow* ptr, const double, const double offset) noexcept {

            auto game = static_cast<Game*>(glfwGetWindowUserPointer(ptr));

            auto entities = game->ecs.entities.entities_with_components<components::camera>();
            auto entity   = std::find_if(entities.begin(), entities.end(), [](entityx::Entity e) {
                return e.component<components::camera>()->main;
            });

            auto camera = (*entity).component<components::camera>();

            camera->fov -= static_cast<float>(offset * 2.0f);
            camera->fov  = glm::clamp(camera->fov, 1.0f, 60.0f);
        });

        glfwSetWindowUserPointer(window, this);
    }


    void Game::init_systems() noexcept
    {
        ecs.systems.add<systems::Camera>();
        ecs.systems.add<systems::Light>();

        ecs.systems.add<systems::Physics>();
        ecs.systems.add<systems::Renderer>();
        ecs.systems.add<systems::Editor>();

        ecs.systems.configure();
    }

    void Game::update_systems(float delta_time)
    {
        ecs.systems.update<systems::Physics>(delta_time);

        ecs.systems.update<systems::Camera>(delta_time);
        ecs.systems.update<systems::Light>(delta_time);
    }

    void Game::draw_systems()
    {
        ecs.systems.update<systems::Renderer>(0);
    }

    void Game::input(const int32_t action, const int32_t key)
    {
        events::Input event { action, key };

        ecs.events.emit(event);

        if (action == GLFW_PRESS) {

            switch (key) {
                case GLFW_KEY_ESCAPE: {
                    _window.close();
                    break;
                }
                case GLFW_KEY_D: {
                    physics.debug();
                    break;
                }
                case GLFW_KEY_P: {
                    _running = !_running;
                    break;
                }
                default:
                    break;
            }
        }
    }

    void Game::mouse(const v2& position)
    {
        _mouse = position;
    }
}
