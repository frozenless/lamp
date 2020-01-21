#include "engine.hpp"

#include "gl/program.hpp"
#include "gl/mesh.hpp"

#include "engine/transform.hpp"
#include "engine/material.hpp"

namespace lamp
{
	void Engine::draw(const transform_ptr& transform, const gl::mesh_ptr& mesh, const material_ptr& material)
	{
		gl::Program::uniform(0, transform->world);

		if (material)
		{
			gl::Program::uniform(1, material->color);
		}

		if (mesh)
		{
			mesh->bind();
			mesh->draw();
		}
	}
}