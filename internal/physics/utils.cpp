#include "utils.hpp"

#include "engine/components/camera.hpp"
#include "engine/components/transform.hpp"
#include "engine/components/viewport.hpp"

namespace lamp::physics
{
	btTransform from(const v3& position, const quat& orientation)
	{
		btTransform transform({ orientation.x, orientation.y, orientation.z, orientation.w },
		                      { position.x, position.y, position.z });
		return transform;
	}

    Ray to_world(entityx::Entity entity, const v2& position)
    {
        auto [ camera, viewport, transform ] = entity.components<components::camera, components::viewport, components::transform>();

        float aspect  = viewport->width / viewport->height;
        m4 projection = glm::perspective(glm::radians(camera->fov), aspect, camera->near, camera->far);

        const m4 inv = glm::inverse(projection * transform->world);

        const float x =  (position.x / viewport->width  - 0.5f) * 2.0f;
        const float y = -(position.y / viewport->height - 0.5f) * 2.0f;

        v4 start = inv * v4(x, y,-1.0f, 1.0f); start /= start.w;
        v4 end   = inv * v4(x, y, 0.0f, 1.0f);   end /= end.w;

        return { start, glm::normalize(end - start) };
    }
}