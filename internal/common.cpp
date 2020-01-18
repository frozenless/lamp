#include "common.hpp"

namespace lamp
{
	std::string read_file(const char* path)
	{
		std::ifstream file(path, std::ios::in);
		assert(file.is_open());

		std::stringstream stream;
		stream << file.rdbuf();

		return stream.str();
	}
}
