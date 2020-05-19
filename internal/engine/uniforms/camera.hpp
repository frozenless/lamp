#pragma once

#include "types.hpp"

namespace lamp::uniforms
{
    struct camera
    {
        m4 proj;
        m4 view;

        v3 position;
    };
}