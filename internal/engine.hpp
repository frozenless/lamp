#pragma once

#include "gl/object.hpp"

namespace lamp
{
	class Engine
	{
	public:
		static void bind(const gl::object_ptr& object);

	private:
		static std::map<gl::Object::Type, gl::Id> bindings;
	};
}

