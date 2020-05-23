#pragma once

#include "types.hpp"
#include "math/rgb.hpp"

namespace lamp::uniforms
{
    struct light
    {
        math::rgb color;
        float ambient;

        v3    position;
        float diffuse;
        float specular;
    };
}