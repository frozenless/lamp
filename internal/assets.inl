#include "gl/assets.hpp"
#include "gl/buffer.inl"
#include "gl/vertex/array.hpp"

#include "engine/mesh.inl"

namespace lamp
{
	template<typename T> gl::buffer_ptr Assets::create(const uint32_t type, const std::pair<const T*, size_t>& data, const uint32_t usage) {

		auto buffer = std::make_shared<gl::Buffer>(type, usage);

		buffer->create();
        buffer->bind();
		buffer->data(data);

		return buffer;
	}

    template<typename T, typename U> std::shared_ptr<Mesh> Assets::create(const std::pair<const T*, size_t>& vertices,
                                               const std::pair<const U*, size_t>& indices, const gl::Layout& layout, const uint32_t primitive, const uint32_t usage) {

        auto  mesh  = std::make_shared<Mesh>(primitive);
        mesh->count = indices.second;
        mesh->type<U>();

        mesh->vao = std::make_shared<gl::vertex::Array>();
        mesh->vao->create();
        mesh->vao->bind();

        mesh->vbo = create(GL_ARRAY_BUFFER,         vertices, usage);
        mesh->ibo = create(GL_ELEMENT_ARRAY_BUFFER, indices,  usage);

        layout.bind();

        return mesh;
    }

    template<typename T, std::size_t S, typename U, std::size_t V> std::shared_ptr<Mesh> Assets::create(const std::array<T, S>& vertices,
                                                                           const std::array<U, V>& indices, const gl::Layout& layout, const uint32_t primitive, const uint32_t usage) {
        return create(std::make_pair(vertices.data(), vertices.size()),
                      std::make_pair(indices.data(),  indices.size()), layout, primitive, usage);
    }

	template<typename T, typename U> std::shared_ptr<Mesh> Assets::create(const std::vector<T>& vertices,
	                                           const std::vector<U>& indices, const gl::Layout& layout, const uint32_t primitive, const uint32_t usage) {

        return create(std::make_pair(vertices.data(), vertices.size()),
                      std::make_pair(indices.data(),  indices.size()), layout, primitive, usage);
	}
}