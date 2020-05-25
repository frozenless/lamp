#include "primitives.hpp"

#include "components/renderer.hpp"
#include "components/transform.hpp"
#include "components/selectable.hpp"

#include "physics/utils.hpp"

#include "assets.inl"
#include "layout.inl"

namespace lamp
{
    entityx::Entity Primitives::create_plane(Physics& physics, entityx::EntityManager& entities, const math::rgb& color, const v3& position, const v3& normal, const float scale, const v3& axes, const float angle)
    {
        const std::array<v3, 8> vertices
        {
            v3(-scale, 0,  scale), v3(0, 1, 0),
            v3( scale, 0,  scale), v3(0, 1, 0),
            v3( scale, 0, -scale), v3(0, 1, 0),
            v3(-scale, 0, -scale), v3(0, 1, 0)
        };

        const std::array<uint32_t, 6> indices
        {
            1, 3, 0,
            1, 2, 3
        };

        gl::Layout layout;
        layout.add<float>(3);
        layout.add<float>(3);

        auto plane    = entities.create();
        auto renderer = plane.assign<components::renderer>();

        renderer->mesh     = Assets::create(vertices, indices, layout, GL_TRIANGLES, GL_STATIC_DRAW);
        renderer->material = std::make_shared<Material>();
        renderer->material->shininess = 128.0f;
        renderer->material->color     = color;

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