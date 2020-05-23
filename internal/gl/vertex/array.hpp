#pragma once

#include "gl/object.hpp"

namespace lamp::gl::vertex
{
    class Array : public Object
    {
    public:
        Array();

        void create()  noexcept final;
        void release() noexcept final;

        void bind() const noexcept final;
    };
}