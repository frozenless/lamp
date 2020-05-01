#pragma once

#include "mesh.hpp"

namespace lamp::gl
{
    template<typename U> constexpr void Mesh::type()
    {
        static_assert(std::is_integral<U>::value);
        if constexpr (std::is_same<U, uint32_t>())
        {
            _type = GL_UNSIGNED_INT;
        }
        else if constexpr (std::is_same<U, uint16_t>())
        {
            _type = GL_UNSIGNED_SHORT;
        }
        else if constexpr (std::is_same<U, uint8_t>())
        {
            _type = GL_UNSIGNED_BYTE;
        }
    }
}