#pragma once

#include "engine/material.hpp"

#include "engine/components/light.hpp"
#include "engine/components/position.hpp"

#include <entityx/entityx.h>

struct GLFWwindow;

namespace lamp::ui
{
    class Editor
    {
    public:
        static void init(GLFWwindow* window);
        static void release();

        static void draw(entityx::ComponentHandle<components::position> position);
        static void draw(entityx::ComponentHandle<components::light>    light);

        static void draw(const std::shared_ptr<Material>& material);

        static void begin();
        static void end();
    };
}
