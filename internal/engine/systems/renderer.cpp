#include "renderer.hpp"

#include "engine/components/renderer.hpp"
#include "engine/components/transform.hpp"

#include "gl/program.hpp"
#include "gl/texture.hpp"

#include "assets.inl"
#include "engine.hpp"

namespace lamp::systems
{
	void Renderer::init()
	{
        _model_buffer    = Assets::create(GL_UNIFORM_BUFFER, GL_DYNAMIC_DRAW, 2);
        _material_buffer = Assets::create(GL_UNIFORM_BUFFER, GL_DYNAMIC_DRAW, 3);
	}

	void Renderer::update(entityx::EntityManager& es, entityx::EventManager&, entityx::TimeDelta)
	{
		es.each<components::renderer, components::transform>([this](entityx::Entity,
		        components::renderer& renderer, components::transform& transform) {

			Engine::bind(renderer.shader);

			if (auto material = renderer.material; material) {

				const math::rgb& color = material->color;
				const std::array<float, 4> uniforms = { color.r, color.g, color.b, material->shininess };

				_material_buffer->data(uniforms);

				if (auto diffuse = material->diffuse; diffuse)
				{
					Engine::bind(diffuse);
				}
			}

			if (renderer.mesh) {

				Engine::bind(renderer.mesh->vao);

				const std::array<m4, 1> uniforms = { transform.world };
				_model_buffer->data(uniforms);

				renderer.mesh->draw();
			}
		});
	}
}