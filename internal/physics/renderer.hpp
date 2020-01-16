#pragma once

#include "types.hpp"

#include <LinearMath/btIDebugDraw.h>
#include <vector>

namespace lamp::debug
{
    class Renderer : public btIDebugDraw
    {
    public:
        Renderer(gl::mesh_ptr mesh, u32 mode);

        void clearLines() final;
        void flushLines() final;

        void drawLine(const btVector3& a, const btVector3& b, const btVector3& color)              final;
        void drawContactPoint(const btVector3&, const btVector3&, btScalar, int, const btVector3&) final;

        void draw3dText(const btVector3&, const char*) final;

        void reportErrorWarning(const char*) final;
        void setDebugMode(int mode)          final;

        int getDebugMode() const final;

    private:
        std::vector<f32> _vertices;
        std::vector<u32> _indices;

	    gl::mesh_ptr _mesh;

        int _index;
        int _mode;
    };
}