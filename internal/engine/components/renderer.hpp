#pragma once

#include "engine/material.hpp"
#include "engine/mesh.hpp"

namespace lamp::components
{
	struct renderer
	{
        gl::program_ptr shader;

		std::shared_ptr<Material> material;
        std::shared_ptr<Mesh>     mesh;
	};
}