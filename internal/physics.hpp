#pragma once

#include "physics/ray.hpp"

#include <btBulletCollisionCommon.h>
#include <BulletCollision/NarrowPhaseCollision/btRaycastCallback.h>

namespace lamp
{
	class Physics
	{
	public:
		static btCollisionWorld::ClosestRayResultCallback ray(btCollisionWorld* world, const Ray& ray);
	};
}