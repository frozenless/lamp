#pragma once

#include "engine/mesh.hpp"

namespace lamp
{
	class Importer
	{
	public:
		static std::shared_ptr<Mesh> import(const char* path, bool drop_normals = false);
	};
}