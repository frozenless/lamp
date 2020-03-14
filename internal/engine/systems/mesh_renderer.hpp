#pragma once

#include <entityx/entityx.h>

namespace lamp::systems
{
	class MeshRenderer : public entityx::System<MeshRenderer>
	{
	public:
		void update(entityx::EntityManager& es, entityx::EventManager& ev, entityx::TimeDelta dt) final;
	};
}