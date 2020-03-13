#pragma once

#include <btBulletDynamicsCommon.h>

namespace lamp::ecs::components
{
	struct RigidBody
	{
		btRigidBody* body;
	};
}