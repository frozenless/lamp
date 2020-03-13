#include "physics.hpp"

#include "ecs/components/transform.hpp"
#include "ecs/components/rigid_body.hpp"

#include <glm/gtc/type_ptr.hpp>

namespace lamp::ecs::systems
{
	void Physics::update(entityx::EntityManager& es, entityx::EventManager&, entityx::TimeDelta)
	{
		es.each<components::RigidBody, components::Transform>([](entityx::Entity,
				components::RigidBody& rigid, components::Transform& transform)
	    {
		    if (rigid.body->isActive())
		    {
			    btTransform bt_transform;
			    rigid.body->getMotionState()->getWorldTransform(bt_transform);

			    bt_transform.getOpenGLMatrix(glm::value_ptr(transform.world));
		    }
	    });
	}
}
