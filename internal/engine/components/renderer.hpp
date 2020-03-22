#pragma once

#include "types.hpp"

namespace lamp::components
{
	struct renderer
	{
		material_ptr material;

		gl::program_ptr shader;
		gl::mesh_ptr    mesh;
	};
}