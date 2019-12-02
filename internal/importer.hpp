#pragma once

#include "common.hpp"

namespace lamp
{
	meshPtr import_mesh(const std::string_view& path, u32 flag = 0);
}