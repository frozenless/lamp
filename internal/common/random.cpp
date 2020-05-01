#include "engine/random.inl"

namespace lamp
{
	void Random::seed()
	{
		srand(static_cast<uint32_t>(time(0)));
	}

	math::rgb Random::color()
	{
		const auto color = Random::linear(glm::zero<v3>(), glm::one<v3>());

		return math::rgb(color.r, color.g, color.b);
	}
}