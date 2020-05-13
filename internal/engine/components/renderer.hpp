#pragma once

#include "types.hpp"

namespace lamp::components
{
	struct renderer
	{
        gl::program_ptr shader;

		material_ptr material;
        mesh_ptr     mesh;
	};
}