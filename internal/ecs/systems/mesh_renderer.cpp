#include "mesh_renderer.hpp"
#include "engine.hpp"

#include "ecs/components/mesh_renderer.hpp"
#include "ecs/components/transform.hpp"

#include "engine/material.hpp"

#include "gl/program.hpp"
#include "gl/texture.hpp"
#include "gl/mesh.hpp"

namespace lamp::ecs::systems
{
	void MeshRenderer::update(entityx::EntityManager& es, entityx::EventManager&, entityx::TimeDelta)
	{
		es.each<components::MeshRenderer, components::Transform>([](entityx::Entity,
				components::MeshRenderer& renderer, components::Transform& transform) {

			Engine::bind(renderer.shader);

			gl::Program::uniform(0, transform.world);

			if (renderer.material)
			{
				gl::Program::uniform(1, renderer.material->color);

				if (auto texture = renderer.material->texture; texture)
				{
					Engine::bind(texture);
				}
			}

			if (renderer.mesh)
			{
				Engine::bind(renderer.mesh);

				renderer.mesh->draw();
			}
		});
	}
}