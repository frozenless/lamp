#include "light.hpp"
#include "assets.inl"

namespace lamp::systems
{
    void Light::configure(entityx::EventManager& events)
    {
        _light_buffer = Assets::create(GL_UNIFORM_BUFFER, GL_DYNAMIC_DRAW, 1);
    }

    void Light::update(entityx::EntityManager& es, entityx::EventManager& ev, entityx::TimeDelta dt)
    {
        es.each<components::light>([this](entityx::Entity,
                components::light& light) {

            const std::array<lamp::components::light, 1> uniforms = { light };

            _light_buffer->data(uniforms);
        });
    }
}