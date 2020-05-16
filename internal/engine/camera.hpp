#pragma once

#include "physics/ray.hpp"

#include <entityx/entityx.h>

namespace lamp
{
    class Camera
    {
    public:
        [[nodiscard]] static Ray to_world(entityx::Entity entity, const v2& position);
    };
}