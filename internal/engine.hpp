#pragma once

#include "types.hpp"

namespace lamp
{
	class Engine
	{
	public:
		static void draw(const transform_ptr& transform, const gl::mesh_ptr& mesh, const material_ptr& material);
	};
}

