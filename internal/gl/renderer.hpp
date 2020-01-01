#pragma once

#include "types.hpp"

namespace lamp::gl
{
	class Renderer
	{
	public:
		static void init();
		static void clear();

		static void set_viewport(const iv4& size);
		static void set_clear_color(const rgb& color);
	};
}