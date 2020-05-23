#pragma once

#include <entityx/entityx.h>

#include "engine/events/camera.hpp"

namespace lamp::systems
{
    class Camera : public entityx::System<Camera>,
                   public entityx::Receiver<Camera> {
    public:
        void configure(entityx::EventManager& events) final;
        void update(entityx::EntityManager& es, entityx::EventManager& ev, entityx::TimeDelta dt) final;

        void receive(const events::CameraAspect& event);

    private:
        gl::buffer_ptr _camera_buffer;
    };
}