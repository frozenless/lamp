#pragma once

#include "physics/ray.hpp"

#include <btBulletDynamicsCommon.h>
#include <BulletCollision/NarrowPhaseCollision/btRaycastCallback.h>

namespace lamp
{
	class Physics
	{
	public:
		Physics();

		Physics(Physics&&)      = delete;
		Physics(const Physics&) = delete;

		Physics& operator=(Physics&&)      = delete;
		Physics& operator=(const Physics&) = delete;

		void init();
		void init_renderer(const gl::mesh_ptr& mesh, uint32_t mode);
		
		void add_rigidbody(btRigidBody* body);
		void add_collision(btCollisionObject* object, uint32_t flag = 0);

		void add_constraint(btTypedConstraint* constraint, bool disable_link);

		btCollisionWorld::ClosestRayResultCallback ray(const Ray& ray);

		void update(float delta_time);
		void debug();

	private:
		std::unique_ptr<btDynamicsWorld> _world;

		bool _show_debug;
	};
}