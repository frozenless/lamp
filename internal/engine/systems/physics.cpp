#include "physics.hpp"

#include "engine/components/transform.hpp"
#include "engine/components/rigidbody.hpp"

#include <glm/gtc/type_ptr.hpp>

namespace lamp::systems
{
	void Physics::update(entityx::EntityManager& es, entityx::EventManager&, entityx::TimeDelta)
	{
		es.each<components::rigidBody, components::transform>([](entityx::Entity,
				components::rigidBody& rigid, components::transform& transform) {

		    if (rigid.body->isActive())
		    {
			    btTransform bt_transform;
			    rigid.body->getMotionState()->getWorldTransform(bt_transform);

			    bt_transform.getOpenGLMatrix(glm::value_ptr(transform.world));
		    }
	    });
	}
}
