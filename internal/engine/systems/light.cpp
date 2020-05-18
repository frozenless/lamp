#include "light.hpp"
#include "assets.inl"

#include "engine/components/position.hpp"
#include "engine/uniforms/light.hpp"

namespace lamp::systems
{
    void Light::configure(entityx::EventManager& events)
    {
        _light_buffer = Assets::create(GL_UNIFORM_BUFFER, GL_DYNAMIC_DRAW, 1);
    }

    void Light::update(entityx::EntityManager& es, entityx::EventManager& ev, entityx::TimeDelta dt)
    {
        es.each<components::light, components::position>([this](entityx::Entity,
                components::light& light, components::position& position) {

            uniforms::light u_light =
            {
                light.color,
                light.ambient,
                {
                    position.x,
                    position.y,
                    position.z
                },
                light.diffuse,
                light.specular
            };

            const std::array<uniforms::light, 1> uniforms = { u_light };

            _light_buffer->data(uniforms);
        });
    }
}