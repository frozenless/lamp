#include "transform.hpp"

#include "engine/components/transform.hpp"
#include "engine/components/position.hpp"
#include "engine/components/scale.hpp"

namespace lamp::systems
{
	void Transform::update(entityx::EntityManager& es, entityx::EventManager&, entityx::TimeDelta)
	{
		es.each<components::transform, components::position, components::scale>([](entityx::Entity,
				components::transform& transform, components::position& position, components::scale& scale) {

			transform.world = glm::translate(glm::identity<m4>(), { position.x, position.y, position.z });
			transform.world = glm::scale(transform.world,         { scale.x, scale.y, scale.z });
		});
	}
}
