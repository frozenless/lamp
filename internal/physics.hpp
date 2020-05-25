#pragma once

#include "physics/ray.hpp"

#include <btBulletDynamicsCommon.h>

namespace lamp
{
	class Physics
	{
	public:
	    Physics() = default;

		Physics(Physics&&)      = delete;
		Physics(const Physics&) = delete;

		Physics& operator=(Physics&&)      = delete;
		Physics& operator=(const Physics&) = delete;

		void init();
        void renderer(btIDebugDraw* renderer);

		void add(btRigidBody* body);
		void add(btCollisionObject* object, btCollisionShape* shape, uint32_t flag = 0);
		void add(btTypedConstraint* constraint, bool disable_link);

		btCollisionWorld::ClosestRayResultCallback ray(const physics::Ray& ray, float distance = 100.0f);

		void update(float delta_time, int32_t steps = 10);
		void debug();

	private:
		std::unique_ptr<btDynamicsWorld> _world;

		bool _show_debug = false;
	};
}