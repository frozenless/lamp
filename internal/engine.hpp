#pragma once

#include "gl/object.hpp"

namespace lamp
{
	class Engine
	{
	public:
		static void bind(const gl::object_ptr& object);
		static void draw(const transform_ptr& transform, const gl::mesh_ptr& mesh, const material_ptr& material);

	private:
		static std::map<gl::Object::Type, gl::handle> bindings;
	};
}

