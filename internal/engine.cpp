#include "engine.hpp"

namespace lamp
{
	std::map<gl::Object::Type, gl::Id> Engine::bindings;

	void Engine::bind(const gl::object_ptr& object)
	{
		if (bindings[object->type()] != object->id()) {
			bindings[object->type()]  = object->id();

			object->bind();
		}
	}
}