#pragma once

#include "types.hpp"

namespace lamp
{
	class Importer
	{
	public:
		static mesh_ptr import(const char* path, bool drop_normals = false);
	};
}