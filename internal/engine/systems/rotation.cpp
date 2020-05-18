#include "rotation.hpp"

#include "engine/components/position.hpp"
#include "engine/components/rotation.hpp"

#include "game.hpp"

namespace lamp::systems
{
    void Rotation::update(entityx::EntityManager& es, entityx::EventManager&, entityx::TimeDelta)
    {
        es.each<components::rotation, components::position>([](entityx::Entity,
                components::rotation& rotation, components::position& position) {

            if (rotation.type == components::rotation::Type::Around) {

                const float value = Game::timer.elapsed() * rotation.speed;

                position.x = rotation.radius * std::cosf(value);
                position.z = rotation.radius * std::sinf(value);
            }
        });
    }
}
