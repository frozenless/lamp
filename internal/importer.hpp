#pragma once

#include "types.hpp"

namespace lamp
{
	gl::mesh_ptr import_mesh(const std::string_view& path, bool drop_normals = false);
}