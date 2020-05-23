#pragma once

#include "ray.hpp"

#include <entityx/entityx.h>
#include <LinearMath/btTransform.h>

namespace lamp::physics
{
    Ray to_world(entityx::Entity entity, const v2& position);
    btTransform from(const v3& position, const quat& orientation);
}