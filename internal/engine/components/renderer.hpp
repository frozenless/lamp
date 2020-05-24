#pragma once

#include "engine/material.hpp"
#include "engine/mesh.hpp"

namespace lamp::components
{
	struct renderer
	{
		std::shared_ptr<Material> material;
        std::shared_ptr<Mesh>     mesh;

        gl::program_ptr shader;
	};
}