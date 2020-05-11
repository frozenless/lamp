#include "utils.hpp"

namespace lamp::utils
{
	btTransform from(const v3& position, const quat& orientation)
	{
		btTransform transform({ orientation.x, orientation.y, orientation.z, orientation.w },
		                      { position.x, position.y, position.z });
		return transform;
	}
}