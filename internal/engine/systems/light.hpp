#pragma once

#include <entityx/entityx.h>

#include "engine/events/light.hpp"

namespace lamp::systems
{
    class Light : public entityx::System<Light>,
                  public entityx::Receiver<Light> {
    public:
        void configure(entityx::EventManager& events) final;
        void update(entityx::EntityManager& es, entityx::EventManager& ev, entityx::TimeDelta dt) final;

        void receive(const events::Light& event);

    private:
        gl::buffer_ptr _light_buffer;
    };
}
