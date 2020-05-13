#pragma once

#include <entityx/entityx.h>

#include "engine/events/camera.hpp"

namespace lamp::systems
{
    class Camera :  public entityx::System<Camera>,
                    public entityx::Receiver<Camera> {
    public:
        void configure(entityx::EventManager& events) final;

        void receive(const events::Camera& event);

    private:
        gl::buffer_ptr _camera_buffer;
    };
}