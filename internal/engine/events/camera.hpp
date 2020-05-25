#pragma once

#include "types.hpp"

#include <entityx/entityx.h>

namespace lamp::events
{
    struct camera_view
    {
        entityx::Entity entity;

        float width;
        float height;
    };
}