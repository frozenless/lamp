#pragma once

#include <entityx/entityx.h>

namespace lamp::systems
{
	class Physics : public entityx::System<Physics>
	{
	private:
		void update(entityx::EntityManager& es, entityx::EventManager& ev, entityx::TimeDelta dt) final;
	};
}