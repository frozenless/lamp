#pragma once

#include "gl/object.hpp"

namespace lamp
{
	class Engine
	{
	public:
		enum class Bindings
		{
			Shader,
			Texture,
			Mesh
		};

		static void bind(Bindings type, const gl::object_ptr& object);
		static void draw(const transform_ptr& transform, const gl::mesh_ptr& mesh, const material_ptr& material);

	private:
		static std::map<Bindings, gl::handle> bindings;
	};
}

