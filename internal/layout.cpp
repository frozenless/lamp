#include "layout.hpp"
#include "util.hpp"

#include <numeric>

namespace lamp
{
	int Layout::calculate_vertex_size(const attributes& attributes) {

		return std::accumulate(attributes.begin(), attributes.end(), 0, [](const int count, const gl::Attribute& attribute) {
			return count + attribute.count * sizeof(f32);
		});
	}
}