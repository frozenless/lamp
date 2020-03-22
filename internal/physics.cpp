#include "physics.hpp"

#include "physics/renderer.hpp"
#include "physics/utils.hpp"

namespace lamp
{
	Physics::Physics()
		: _show_debug(false)
	{
	}

	void Physics::init()
	{
		auto config = new btDefaultCollisionConfiguration();

		_world = std::make_unique<btDiscreteDynamicsWorld>(
				new btCollisionDispatcher(config), new btDbvtBroadphase(),
				new btSequentialImpulseConstraintSolver(), config);

		_world->setGravity(btVector3(0, -9.8f, 0));
	}

	btCollisionWorld::ClosestRayResultCallback Physics::ray(const Ray& ray)
	{
		const v3 end = ray.origin + ray.direction * 100.0f;

		btCollisionWorld::ClosestRayResultCallback hit(utils::from(ray.origin), utils::from(end));
		_world->rayTest(utils::from(ray.origin), utils::from(end), hit);

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

		if (_show_debug)
		{
			_world->debugDrawWorld();
		}
	}

	void Physics::init_renderer(const gl::mesh_ptr& mesh, const uint32_t mode)
	{
		_world->setDebugDrawer(new lamp::debug::Renderer(mesh, mode));
	}

	void Physics::toggle_debug()
	{
		_show_debug = !_show_debug;
	}

	bool Physics::debug() const
	{
		return _show_debug;
	}
}