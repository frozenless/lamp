#include "file.hpp"

namespace lamp
{
	std::string File::read(const char* path)
	{
        assert(path != nullptr);

		std::ifstream file(path, std::ios::in);
		assert(file.is_open());

		std::stringstream stream;
		stream << file.rdbuf();

		return stream.str();
	}
}
