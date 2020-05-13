#pragma once

#include "engine/mesh.hpp"

#include <LinearMath/btIDebugDraw.h>

namespace lamp::debug
{
    class Renderer : public btIDebugDraw
    {
    public:
        Renderer(std::shared_ptr<Mesh> mesh, uint32_t mode);

        void clearLines() final;
        void flushLines() final;

        void drawLine(const btVector3& a, const btVector3& b, const btVector3& color) final;
        void setDebugMode(int32_t mode)   final;

	    [[nodiscard]]
	    int32_t getDebugMode() const final;

    private:
        void drawContactPoint(const btVector3&, const btVector3&, btScalar, int32_t, const btVector3&) final { };
        void draw3dText(const btVector3&, const char*) final { };
        void reportErrorWarning(const char*)           final { };

    private:
        std::vector<v3>       _vertices;
        std::vector<uint32_t> _indices;

        std::shared_ptr<Mesh> _mesh;

	    int32_t _index;
	    int32_t _mode;
    };
}