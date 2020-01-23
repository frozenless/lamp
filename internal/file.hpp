#pragma once

#include "utils/dependencies.hpp"

namespace lamp
{
	class File
	{
	public:
		static std::string read(const char* path);
	};
}