#pragma once

#include "types.hpp"

#include <LinearMath/btTransform.h>

namespace lamp::utils
{
	btTransform from(const v3& position, const quat& orientation);
}