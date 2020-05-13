#include "random.hpp"

namespace lamp
{
	void Random::seed()
	{
		srand(static_cast<uint32_t>(time(0)));
	}

	math::rgb Random::color()
	{
		const auto color = Random::linear(glm::zero<v3>(), glm::one<v3>());

		return { color.r, color.g, color.b };
	}
}