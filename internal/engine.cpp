#include "engine.hpp"

#include "gl/program.hpp"
#include "gl/mesh.hpp"

#include "engine/transform.hpp"
#include "engine/material.hpp"

namespace lamp
{
	std::map<Engine::Bindings, gl::handle> Engine::bindings;

	void Engine::bind(const Bindings type, const gl::object_ptr& object)
	{
		if (bindings[type] != object->id) {
			bindings[type]  = object->id;

			object->bind();
		}
	}

	void Engine::draw(const transform_ptr& transform, const gl::mesh_ptr& mesh, const material_ptr& material)
	{
		gl::Program::uniform(0, transform->world);

		if (material)
		{
			gl::Program::uniform(1, material->color);
		}

		if (mesh)
		{
			Engine::bind(Bindings::Mesh, mesh);

			mesh->draw();
		}
	}
}