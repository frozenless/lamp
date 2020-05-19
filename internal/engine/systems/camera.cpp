#include "camera.hpp"
#include "assets.inl"

#include "engine/components/camera.hpp"
#include "engine/components/transform.hpp"
#include "engine/components/position.hpp"
#include "engine/components/viewport.hpp"

#include "engine/uniforms/camera.hpp"

namespace lamp::systems
{
    void Camera::configure(entityx::EventManager& events)
    {
        events.subscribe<events::CameraAspect>(*this);

        _camera_buffer = Assets::create(GL_UNIFORM_BUFFER, GL_DYNAMIC_DRAW, 0);
    }

    void Camera::update(entityx::EntityManager& es, entityx::EventManager&, entityx::TimeDelta)
    {
        es.each<components::camera, components::viewport, components::transform, components::position>([this](entityx::Entity,
                components::camera& camera, components::viewport& viewport, components::transform& transform, components::position& position) {

            transform.world = glm::translate(glm::identity<m4>(), { position.x, position.y, position.z });
            transform.world = glm::inverse(transform.world);

            if (camera.main)
            {
                const float aspect = viewport.width / viewport.height;
                m4 projection = glm::perspective(glm::radians(camera.fov), aspect, camera.near, camera.far);

                const uniforms::camera u_camera =
                {
                    projection,
                    transform.world,
                    {
                        position.x,
                        position.y,
                        position.z
                    }
                };

                const std::array<uniforms::camera, 1> uniforms = { u_camera };
                _camera_buffer->data(uniforms);
            }
        });
    }

    void Camera::receive(const events::CameraAspect& event)
    {
        m4 projection;

        auto entity = event.entity;
        auto camera = entity.component<components::camera>();

        if (camera->type == components::camera::Type::Perspective)
        {
            const float aspect = event.width / event.height;

            projection = glm::perspective(glm::radians(camera->fov), aspect, camera->near, camera->far);
        }
        else if (camera->type == components::camera::Type::Orthographic)
        {
            projection = glm::ortho(0.0f, event.width, 0.0f, event.height, 1.0f, -1.0f);
        }

        const std::array<m4, 1> uniforms = { projection };
        _camera_buffer->sub_data(std::make_pair(uniforms.data(), uniforms.size()), 0);
    }
}