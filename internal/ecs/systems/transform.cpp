#include "transform.hpp"

#include "ecs/components/transform.hpp"
#include "ecs/components/position.hpp"
#include "ecs/components/scale.hpp"

namespace lamp::ecs::systems
{
	void Transform::update(entityx::EntityManager& es, entityx::EventManager&, entityx::TimeDelta)
	{
		es.each<components::Transform, components::Position, components::Scale>([](entityx::Entity,
				components::Transform& transform, components::Position& position, components::Scale& scale)
		{
			transform.world = glm::translate(glm::identity<m4>(), lamp::v3(position.x, position.y, position.z));
			transform.world = glm::scale(transform.world, lamp::v3(scale.x, scale.y, scale.z));
		});
	}
}
