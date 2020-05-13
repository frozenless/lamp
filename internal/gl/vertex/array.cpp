#include "array.hpp"

#include <glad/glad.h>

namespace lamp::gl::vertex
{
    Array::Array()
        : Object(Type::VertexArray)
    {
    }

    void Array::create() noexcept
    {
        glCreateVertexArrays(1, &id);
    }

    void Array::release() noexcept
    {
        glDeleteVertexArrays(1, &id);
    }

    void Array::bind() const noexcept
    {
        glBindVertexArray(id);
    }
}
