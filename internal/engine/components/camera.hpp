#pragma once

namespace lamp::components
{
    struct camera
    {
        enum class Type
        {
            Perspective,
            Orthographic
        };

        Type type  = Type::Perspective;
        float fov  = 60.0f;
        float far  = 100.0f;
        float near = 0.1f;

        bool main;
    };
}