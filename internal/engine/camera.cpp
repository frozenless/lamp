#include "camera.hpp"

#include "engine/components/camera.hpp"
#include "engine/components/transform.hpp"

namespace lamp
{
    Ray Camera::to_world(entityx::Entity entity, const v2& position)
    {
        v2 size = { 1280.0f, 768.0f };

        float aspect = 1280.0f / 768.0f;

        auto transform = entity.component<components::transform>();
        auto camera    = entity.component<components::camera>();

        m4 projection = glm::perspective(glm::radians(camera->fov), aspect, camera->near, camera->far);

        const m4 inv = glm::inverse(projection * transform->world);

        const float x =  (position.x / size.x - 0.5f) * 2.0f;
        const float y = -(position.y / size.y - 0.5f) * 2.0f;

        v4 start = inv * v4(x, y,-1.0f, 1.0f); start /= start.w;
        v4 end   = inv * v4(x, y, 0.0f, 1.0f);   end /= end.w;

        return Ray(start, glm::normalize(end - start));
    }
}