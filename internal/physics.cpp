#include "physics.hpp"

namespace lamp
{
	btCollisionWorld::ClosestRayResultCallback ray(btCollisionWorld* world, const v3& origin, const v3& direction)
	{
		const v3 end = origin + direction * 100.0f;
		btCollisionWorld::ClosestRayResultCallback hit(btVector3(origin.x, origin.y, origin.z),
												         btVector3(end.x, end.y, end.z));

		world->rayTest(btVector3(origin.x, origin.y, origin.z),
		                 btVector3(end.x, end.y, end.z), hit);
		return hit;
	}
}