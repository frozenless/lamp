#include "engine/random.inl"

namespace lamp
{
	void Random::seed()
	{
		srand(static_cast<uint32_t>(time(0)));
	}

	rgb Random::color()
	{
		return Random::linear(glm::zero<v3>(), glm::one<v3>());
	}
}