#include "camera.hpp"
#include "assets.inl"

#include "engine/components/camera.hpp"
#include "engine/components/transform.hpp"
#include "engine/components/position.hpp"

namespace lamp::systems
{
    void Camera::configure(entityx::EventManager& events)
    {
        events.subscribe<events::CameraAspect>(*this);

        _camera_buffer          = Assets::create(GL_UNIFORM_BUFFER, GL_DYNAMIC_DRAW, 0);
        _camera_position_buffer = Assets::create(GL_UNIFORM_BUFFER, GL_DYNAMIC_DRAW, 4);
    }

    void Camera::update(entityx::EntityManager& es, entityx::EventManager&, entityx::TimeDelta)
    {
        es.each<components::camera, components::transform, components::position>([this](entityx::Entity,
                                                                                        components::camera& camera, components::transform& transform, components::position& position) {

            transform.world = glm::translate(glm::identity<m4>(), { position.x, position.y, position.z });
            transform.world = glm::inverse(transform.world);

            if (camera.main)
            {
                m4 projection = glm::perspective(glm::radians(camera.fov), 1280.0f / 768.0f, camera.near, camera.far);

                const std::array<lamp::m4, 2> uniforms = { transform.world, projection  };
                _camera_buffer->data(std::make_pair(uniforms.data(), uniforms.size()));

                const std::array<lamp::v3, 1> u_camera_position = { v3(position.x, position.y, position.z) };
                _camera_position_buffer->data(u_camera_position);
            }
        });
    }

    void Camera::receive(const events::CameraAspect& event)
    {
        /*auto camera = event.entity.component<components::camera>();
        m4 projection;

        if (camera->type == components::camera::Type::Perspective)
        {
            const float aspect = event.width / event.height;

            projection = glm::perspective(glm::radians(camera->fov), aspect, camera->near, camera->far);
        }
        else if (camera->type == components::camera::Type::Orthographic)
        {
            projection = glm::ortho(0.0f, event.width, 0.0f, event.height, 1.0f, -1.0f);
        }

        const std::array<lamp::m4, 1> uniforms = { projection };
        _camera_buffer->sub_data(std::make_pair(uniforms.data(), uniforms.size()), 1);*/
    }
}