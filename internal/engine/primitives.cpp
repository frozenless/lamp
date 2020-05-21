#include "primitives.hpp"

#include "components/renderer.hpp"
#include "components/transform.hpp"
#include "components/selectable.hpp"

#include "physics/utils.hpp"
#include "importer.hpp"

namespace lamp
{
    entityx::Entity Primitives::create_plane(Physics& physics, entityx::EntityManager& entities, const math::rgb& color, const v3& position, const v3& normal, const v3& axes, const float angle)
    {
        auto plane    = entities.create();
        auto renderer = plane.assign<components::renderer>();

        renderer->mesh     = Importer::import("models/plane.obj");
        renderer->material = std::make_shared<Material>();
        renderer->material->color     = color;
        renderer->material->shininess = 128.0f;

        auto world = glm::translate(glm::identity<m4>(), position);
        plane.assign<components::transform>()->world = glm::rotate(world, glm::radians(angle), axes);
        plane.assign<components::selectable>();

        btRigidBody::btRigidBodyConstructionInfo info(0.0f,
                                                      new btDefaultMotionState(physics::from(position, glm::identity<quat>())),
                                                      new btStaticPlaneShape({ normal.x, normal.y, normal.z }, 0));
        auto body = new btRigidBody(info);
        body->setUserIndex(static_cast<int32_t>(plane.id().id()));

        physics.add(body);

        return plane;
    }
}