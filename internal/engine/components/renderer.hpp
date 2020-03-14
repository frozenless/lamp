#pragma once

#include "types.hpp"

namespace lamp::components
{
	struct Renderer
	{
		material_ptr material;

		gl::program_ptr shader;
		gl::mesh_ptr    mesh;
	};
}