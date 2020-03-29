#pragma once

#include <entityx/entityx.h>

#include "types.hpp"

namespace lamp::systems
{
	class Renderer : public entityx::System<Renderer>
	{
	public:
		void init();

		void update(entityx::EntityManager& es, entityx::EventManager& ev, entityx::TimeDelta dt) final;

	private:
		gl::buffer_ptr material_buffer;
		gl::buffer_ptr model_buffer;
	};
}