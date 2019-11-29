#include "gl/attribute.hpp"
#include <vector>

namespace lamp
{
	struct Layout
	{
		static int calculate_vertex_size(const std::vector<gl::Attribute>& attributes);
	};
}