#include "physics.hpp"
#include "physics/utils.hpp"

namespace lamp
{
	btCollisionWorld::ClosestRayResultCallback Physics::ray(btCollisionWorld* world, const Ray& ray)
	{
		const v3 end = ray.origin + ray.direction * 100.0f;

		btCollisionWorld::ClosestRayResultCallback hit(math::from(ray.origin), math::from(end));
		world->rayTest(math::from(ray.origin), math::from(end), hit);

		return hit;
	}
}