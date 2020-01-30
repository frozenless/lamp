#pragma once

#include "object.hpp"

namespace lamp::gl
{
	class Renderer
	{
	public:
		static void init();
		static void init_blending();

		static void set_viewport(const iv4& size);
		static void set_clear_color(const rgb& color);

		static void set_wire_mode(bool value);

		static void enable(u32 value);
		static void disable(u32 value);

		static void clear();
	};
}