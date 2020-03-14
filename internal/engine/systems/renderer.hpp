#pragma once

#include <entityx/entityx.h>

namespace lamp::systems
{
	class Renderer : public entityx::System<Renderer>
	{
	public:
		void update(entityx::EntityManager& es, entityx::EventManager& ev, entityx::TimeDelta dt) final;
	};
}