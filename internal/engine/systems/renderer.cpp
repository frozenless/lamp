#include "renderer.hpp"
#include "engine.hpp"
#include "assets.inl"

#include "engine/components/renderer.hpp"
#include "engine/components/transform.hpp"

#include "engine/material.hpp"

#include "gl/program.hpp"
#include "gl/texture.hpp"

namespace lamp::systems
{
	void Renderer::init()
	{
		std::array<m4, 1> model_uniforms = { };
		model_buffer = Assets::create(GL_UNIFORM_BUFFER, model_uniforms.data(), model_uniforms.size(), GL_DYNAMIC_DRAW);
		model_buffer->bind_base(2);

		std::array<v4, 1> material_uniforms = { };
		material_buffer = Assets::create(GL_UNIFORM_BUFFER, material_uniforms.data(), material_uniforms.size(), GL_DYNAMIC_DRAW);
		material_buffer->bind_base(3);
	}

	void Renderer::update(entityx::EntityManager& es, entityx::EventManager&, entityx::TimeDelta)
	{
		es.each<components::renderer, components::transform>([this](entityx::Entity,
		        components::renderer& renderer, components::transform& transform) {

			Engine::bind(renderer.shader);

			if (auto material = renderer.material; material) {

				std::array<v4, 1> uniforms = { v4(material->color, material->shininess) };
				material_buffer->set_data(uniforms);

				if (auto diffuse = material->diffuse; diffuse)
				{
					Engine::bind(diffuse);
				}
			}

			if (renderer.mesh) {

				Engine::bind(renderer.mesh);

				std::array<m4, 1> uniforms = { transform.world };
				model_buffer->set_data(uniforms);

				renderer.mesh->draw();
			}
		});
	}
}