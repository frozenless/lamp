#pragma once

#include <entityx/entityx.h>

namespace lamp::systems
{
    class Rotation : public entityx::System<Rotation>
    {
    public:
        void configure(entityx::EventManager& events) final;
        void update(entityx::EntityManager& es, entityx::EventManager& ev, entityx::TimeDelta dt) final;
    };
}