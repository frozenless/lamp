#pragma once

#include "types.hpp"

#include <entityx/entityx.h>

namespace lamp::events
{
    struct CameraAspect
    {
        entityx::Entity entity;

        float width;
        float height;
    };
}