#include "physics.hpp"

namespace lamp
{
	void Physics::init()
	{
		auto config = new btDefaultCollisionConfiguration();

		_world = std::make_unique<btDiscreteDynamicsWorld>(
				new btCollisionDispatcher(config), new btDbvtBroadphase(),
				new btSequentialImpulseConstraintSolver(), config);

		_world->setGravity({ 0, -9.8f, 0 });
	}

	btCollisionWorld::ClosestRayResultCallback Physics::ray(const physics::Ray& ray, const float distance)
	{
		const v3 end = ray.origin + ray.direction * distance;

		btCollisionWorld::ClosestRayResultCallback hit({ ray.origin.x, ray.origin.y, ray.origin.z },
		                                               { end.x, end.y, end.z });

		_world->rayTest({ ray.origin.x, ray.origin.y, ray.origin.z },
		                { end.x, end.y, end.z }, hit);
		return hit;
	}

	void Physics::add(btRigidBody* body)
	{
		_world->addRigidBody(body);
	}

	void Physics::add(btCollisionObject* object, btCollisionShape* shape, const uint32_t flag)
	{
        if (shape)
        {
            object->setCollisionShape(shape);
        }

		if (flag)
		{
			object->setCollisionFlags(flag);
		}

		_world->addCollisionObject(object);
	}

	void Physics::add(btTypedConstraint* constraint, const bool disable_link)
	{
		_world->addConstraint(constraint, disable_link);
	}

	void Physics::update(const float delta_time, const int32_t steps)
	{
		_world->stepSimulation(delta_time, steps);

		if (_show_debug)
		{
			_world->debugDrawWorld();
		}
	}

	void Physics::renderer(btIDebugDraw* renderer)
	{
		_world->setDebugDrawer(renderer);
	}

	void Physics::debug()
	{
		_show_debug = !_show_debug;

		if (!_show_debug)
		{
			_world->getDebugDrawer()->clearLines();
		}
	}
}