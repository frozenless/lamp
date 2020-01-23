#pragma once

#include "dependencies.hpp"

namespace lamp
{
	class File
	{
	public:
		static std::string read(const char* path);
	};
}