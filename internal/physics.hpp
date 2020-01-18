#pragma once

#include "physics/ray.hpp"
#include "physics/renderer.hpp"

#include <btBulletDynamicsCommon.h>
#include <BulletCollision/NarrowPhaseCollision/btRaycastCallback.h>

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
		void update(f32 delta_time);

		void add_rigidbody(btRigidBody* body);
		void add_collision(btCollisionObject* object);

		void set_renderer(debug::Renderer* renderer);

		btCollisionWorld::ClosestRayResultCallback ray(const Ray& ray);

	private:
		std::unique_ptr<btDynamicsWorld> _world;
	};
}