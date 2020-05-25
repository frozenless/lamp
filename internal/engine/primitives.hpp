#pragma once

#include "types.hpp"
#include "physics.hpp"
#include "math/rgb.hpp"

#include <entityx/entityx.h>

namespace lamp
{
    class Primitives
    {
    public:
        static entityx::Entity create_plane(Physics& physics, entityx::EntityManager& entities, const math::rgb& color, const v3& position, const v3& normal, float scale, const v3& axes, float angle);
    };
}