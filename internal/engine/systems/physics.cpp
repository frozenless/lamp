#include "physics.hpp"

#include "engine/components/transform.hpp"
#include "engine/components/rigidbody.hpp"

#include <glm/gtc/type_ptr.hpp>

namespace lamp::systems
{
	void Physics::update(entityx::EntityManager& es, entityx::EventManager&, entityx::TimeDelta)
	{
		es.each<components::rigidbody, components::transform>([](entityx::Entity,
		        components::rigidbody& rigid, components::transform& transform) {

		    if (rigid.body->isActive())
		    {
			    btTransform bt_transform;

		    	if (auto motion = rigid.body->getMotionState(); motion)
		    	{
				    motion->getWorldTransform(bt_transform);
			    }
		    	else
	            {
					bt_transform = rigid.body->getWorldTransform();
		    	}

			    bt_transform.getOpenGLMatrix(glm::value_ptr(transform.world));
		    }
	    });
	}
}
