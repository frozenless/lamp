#pragma once

#include <entityx/entityx.h>

#include "engine/events/light.hpp"

namespace lamp::systems
{
    class Light : public entityx::System<Light>
    {
    public:
        void configure(entityx::EventManager& events) final;
        void update(entityx::EntityManager& es, entityx::EventManager& ev, entityx::TimeDelta dt) final;

    private:
        gl::buffer_ptr _light_buffer;
    };
}
