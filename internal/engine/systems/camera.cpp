#include "camera.hpp"
#include "assets.inl"

namespace lamp::systems
{
    void Camera::configure(entityx::EventManager& events)
    {
        events.subscribe<events::Camera>(*this);

        _camera_buffer = Assets::create(GL_UNIFORM_BUFFER, GL_DYNAMIC_DRAW, 2);
    }

    void Camera::receive(const events::Camera& event)
    {
        std::cout << "test" << std::endl;
    }
}