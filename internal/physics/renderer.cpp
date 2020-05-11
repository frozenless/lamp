#include "renderer.hpp"
#include "engine.hpp"

#include "gl/mesh.hpp"
#include "gl/buffer.inl"

namespace lamp::debug
{
    Renderer::Renderer(gl::mesh_ptr mesh, const uint32_t mode)
        : _mesh(std::move(mesh))
	    , _mode(mode)
        , _index(0)
    {
    }

    void Renderer::drawLine(const btVector3& a, const btVector3& b, const btVector3& color)
    {
        _vertices.insert(std::end(_vertices), {
            { a.x(), a.y(), a.z() }, { color.x(), color.y(), color.z() },
            { b.x(), b.y(), b.z() }, { color.x(), color.y(), color.z() }
        });

        _indices.emplace_back(_index++);
        _indices.emplace_back(_index++);
    }

    void Renderer::clearLines()
    {
        _vertices.clear();
        _indices.clear();

	    _mesh->count = 0;
	    _index       = 0;
    }

    void Renderer::flushLines()
    {
    	if (!_vertices.empty() && !_indices.empty()) {

		    _mesh->bind();

		    _mesh->vbo->data(_vertices);
		    _mesh->ibo->data(_indices);

		    _mesh->count = _indices.size();
	    }
    }

	void Renderer::setDebugMode(const int32_t mode)
	{
    	_mode = mode;
	}

	int32_t Renderer::getDebugMode() const
	{
		return _mode;
	}

    void Renderer::drawContactPoint(const btVector3&, const btVector3&, const btScalar, const int32_t, const btVector3&) { }
	void Renderer::draw3dText(const btVector3&, const char*) { }

	void Renderer::reportErrorWarning(const char*) { }
}