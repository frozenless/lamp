#include "physics.hpp"
#include "physics/utils.hpp"

namespace lamp
{
	void Physics::init()
	{
		auto config = new btDefaultCollisionConfiguration();

		_world = std::make_unique<btDiscreteDynamicsWorld>(
				new btCollisionDispatcher(config), new btDbvtBroadphase(),
				new btSequentialImpulseConstraintSolver(), config);

		_world->setGravity(btVector3(0, -9.8f, 0));
	}

	void Physics::set_renderer(debug::Renderer* renderer)
	{
		_world->setDebugDrawer(renderer);
	}

	btCollisionWorld::ClosestRayResultCallback Physics::ray(const Ray& ray)
	{
		const v3 end = ray.origin + ray.direction * 100.0f;

		btCollisionWorld::ClosestRayResultCallback hit(math::from(ray.origin), math::from(end));
		_world->rayTest(math::from(ray.origin), math::from(end), hit);

		return hit;
	}

	void Physics::add_rigidbody(btRigidBody* body)
	{
		_world->addRigidBody(body);
	}

	void Physics::add_collision(btCollisionObject* object)
	{
		_world->addCollisionObject(object);
	}

	void Physics::update(const f32 delta_time)
	{
		_world->stepSimulation(delta_time, 10);
		_world->debugDrawWorld();
	}
}