#pragma once

#include "types.hpp"

#include <entityx/entityx.h>

namespace lamp::events
{
    struct CameraAspect
    {
        const entityx::Entity entity;

        float width;
        float height;
    };
}