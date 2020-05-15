#include "editor.hpp"

#include "engine/components/selectable.hpp"
#include "engine/components/renderer.hpp"

#include "engine/editor.hpp"

#include <GLFW/glfw3.h>

namespace lamp::systems
{
    void Editor::configure(entityx::EventManager& events)
    {
        events.subscribe<events::Input>(*this);
    }

    void Editor::update(entityx::EntityManager& es, entityx::EventManager& ev, entityx::TimeDelta)
    {
        if (!_show_editor) return;

        es.each<components::selectable>([this](entityx::Entity entity,
                components::selectable& selectable) {

            if (selectable.selected) {

                if (entity.has_component<components::renderer>()) {
                    ui::Editor::draw(entity.component<components::renderer>()->material);
                }

                if (entity.has_component<components::light>()) {
                    ui::Editor::draw(entity.component<components::light>());
                }
            }
        });
    }

    void Editor::receive(const events::Input& event)
    {
        if (event.action == GLFW_PRESS && event.key == GLFW_KEY_E)
        {
            _show_editor = !_show_editor;
        }
    }
}
