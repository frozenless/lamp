#include "random.hpp"
#include "types.hpp"

namespace lamp
{
	void Random::seed()
	{
		srand(static_cast<uint32_t>(time(0)));
	}
}