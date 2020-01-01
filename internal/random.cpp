#include "random.hpp"
#include "types.hpp"

#include <ctime>

namespace lamp
{
	void Random::seed()
	{
		srand(static_cast<u32>(time(0)));
	}
}