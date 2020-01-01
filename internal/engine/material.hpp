#pragma once

#include "types.hpp"

namespace lamp
{
	struct Material
	{
		explicit Material(const rgb& color = rgb(1.0f));

		rgb color;
	};
}