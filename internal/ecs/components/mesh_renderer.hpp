#pragma once

#include "types.hpp"

namespace lamp::ecs::components
{
	struct MeshRenderer
	{
		material_ptr material;

		gl::program_ptr shader;
		gl::mesh_ptr    mesh;
	};
}