#include "common.hpp"

#include <sstream>
#include <fstream>
#include <ctime>

namespace lamp
{
	std::string read_file(const std::string_view& path)
	{
		std::ifstream file(path.data(), std::ios::in);

		if (file.is_open())
		{
			std::stringstream stream;
			stream << file.rdbuf();

			return stream.str();
		}

		return std::string();
	}
}
