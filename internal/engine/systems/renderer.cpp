#include "renderer.hpp"

#include "engine/components/renderer.hpp"
#include "engine/components/transform.hpp"

#include "engine/material.hpp"

#include "engine.hpp"

#include "gl/program.hpp"
#include "gl/texture.hpp"
#include "gl/mesh.hpp"

namespace lamp::systems
{
	void Renderer::update(entityx::EntityManager& es, entityx::EventManager&, entityx::TimeDelta)
	{
		es.each<components::renderer, components::transform>([](entityx::Entity,
		        components::renderer& renderer, components::transform& transform) {

			Engine::bind(renderer.shader);

			gl::Program::uniform(0, transform.world);

			if (renderer.material) {

				gl::Program::uniform(1, renderer.material->color);

				if (auto texture = renderer.material->texture; texture)
				{
					Engine::bind(texture);
				}
			}

			if (renderer.mesh) {

				Engine::bind(renderer.mesh);

				renderer.mesh->draw();
			}
		});
	}
}