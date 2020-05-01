#pragma once

#include <entityx/entityx.h>

namespace lamp::systems
{
	class Transform : public entityx::System<Transform>
	{
	public:
		void update(entityx::EntityManager& es, entityx::EventManager& ev, entityx::TimeDelta dt) final;
	};
}