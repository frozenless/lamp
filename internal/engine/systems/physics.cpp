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

		    if (btTransform t; rigid.body->isActive())
		    {
		    	if (auto motion = rigid.body->getMotionState(); motion)
		    	{
				    motion->getWorldTransform(t);
			    }
		    	else
	            {
                    t = rigid.body->getWorldTransform();
		    	}

                t.getOpenGLMatrix(glm::value_ptr(transform.world));
		    }
	    });
	}
}
