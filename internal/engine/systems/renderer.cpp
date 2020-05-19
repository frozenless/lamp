#include "renderer.hpp"
#include "engine.hpp"
#include "assets.inl"

#include "engine/components/renderer.hpp"
#include "engine/components/transform.hpp"

#include "engine/uniforms/material.hpp"

#include "gl/program.hpp"
#include "gl/texture.hpp"
#include "gl/renderer.hpp"

#include <GLFW/glfw3.h>

namespace lamp::systems
{
    void Renderer::configure(entityx::EventManager& events)
	{
        events.subscribe<events::Input>(*this);

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

			    uniforms::material u_material =
                {
                    {
                        color.r,
                        color.g,
                        color.b
                    },
                    material->shininess
                };

				const std::array<uniforms::material, 1> uniforms = { u_material };
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

    void Renderer::receive(const events::Input& event)
    {
        if (event.action == GLFW_PRESS && event.key == GLFW_KEY_W)
        {
            gl::Renderer::wire_mode(_wire_mode);

            _wire_mode = !_wire_mode;
        }
    }
}