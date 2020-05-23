#pragma once

#include <entityx/entityx.h>

#include "engine/events/input.hpp"

namespace lamp::systems
{
    class Editor : public entityx::System<Editor>,
                   public entityx::Receiver<Editor> {
    public:
        void configure(entityx::EventManager& events) final;
        void update(entityx::EntityManager& es, entityx::EventManager& ev, entityx::TimeDelta dt) final;

        void receive(const events::Input& event);

    private:
        bool _show_editor = false;
    };
}
