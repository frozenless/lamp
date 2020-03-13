#include "random.hpp"
#include "types.hpp"

namespace lamp
{
	void Random::seed()
	{
		srand(static_cast<u32>(time(0)));
	}
}