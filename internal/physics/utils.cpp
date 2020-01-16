#include "utils.hpp"

namespace lamp::math
{
	btVector3 from(const v3& vec)
	{
		return btVector3(vec.x, vec.y, vec.z);
	}
}