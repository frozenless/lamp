#pragma once

namespace lamp::components
{
    struct rotation
    {
        enum class Type
        {
            Around
        };

        Type  type = Type::Around;

        float radius;
        float speed;
    };
}