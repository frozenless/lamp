#pragma once

#include <entityx/entityx.h>

#include "engine/events/input.hpp"

namespace lamp::systems
{
	class Renderer : public entityx::System<Renderer>,
                     public entityx::Receiver<Renderer> {
	public:
        void configure(entityx::EventManager& events) final;
		void update(entityx::EntityManager& es, entityx::EventManager& ev, entityx::TimeDelta dt) final;

        void receive(const events::Input& event);

	private:
		gl::buffer_ptr _material_buffer;
		gl::buffer_ptr _model_buffer;

        bool _wire_mode = true;
	};
}