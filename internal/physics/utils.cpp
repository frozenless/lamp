#include "utils.hpp"

namespace lamp::utils
{
	btVector3 from(const v3& vec)
	{
		return btVector3(vec.x, vec.y, vec.z);
	}

	btTransform from(const v3& position, const quat& orientation)
	{
		btTransform transform;

		transform.setOrigin(from(position));
		transform.setRotation(btQuaternion(orientation.x, orientation.y, orientation.z, orientation.w));

		return transform;
	}
}