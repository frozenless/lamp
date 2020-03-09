#pragma once

#include "types.hpp"

#include <LinearMath/btVector3.h>
#include <LinearMath/btTransform.h>

namespace lamp::utils
{
	btVector3   from(const v3& vec);
	btTransform from(const v3& position, const quat& orientation);
}