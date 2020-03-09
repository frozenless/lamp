#include "engine.hpp"

#include "gl/texture.hpp"
#include "gl/program.hpp"
#include "gl/mesh.hpp"

#include "engine/transform.hpp"
#include "engine/material.hpp"

namespace lamp
{
	std::map<gl::Object::Type, gl::ID> Engine::bindings;

	void Engine::bind(const gl::object_ptr& object)
	{
		if (bindings[object->type] != object->id) {
			bindings[object->type]  = object->id;

			object->bind();
		}
	}

	void Engine::draw(const transform_ptr& transform, const gl::mesh_ptr& mesh, const material_ptr& material)
	{
		gl::Program::uniform(0, transform->world);

		if (material)
		{
			gl::Program::uniform(1, material->color);

			if (auto texture = material->texture; texture)
			{
				Engine::bind(texture);
			}
		}

		if (mesh)
		{
			Engine::bind(mesh); mesh->draw();
		}
	}
}