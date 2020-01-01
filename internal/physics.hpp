#pragma once

#include "types.hpp"

#include <btBulletCollisionCommon.h>
#include <BulletCollision/NarrowPhaseCollision/btRaycastCallback.h>

namespace lamp
{
	btCollisionWorld::ClosestRayResultCallback ray(btCollisionWorld* world, const v3& origin, const v3& direction);
}