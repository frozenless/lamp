#pragma once

#include <entityx/entityx.h>

namespace lamp::systems
{
	class Physics : public entityx::System<Physics>
	{
	public:
		void update(entityx::EntityManager& es, entityx::EventManager& ev, entityx::TimeDelta dt) final;
	};
}