#pragma once

#include "types.hpp"

namespace lamp::uniforms
{
    struct camera
    {
        m4 view;
        m4 proj;

        v3 position;
    };
}