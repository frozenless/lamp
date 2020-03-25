#pragma once

#include "types.hpp"

namespace lamp::gl
{
	class Renderer
	{
	public:
		static void init();
		static void init_blending();

		static void set_viewport(const iv4& size);
		static void set_clear_color(const rgb& color);

		static void set_state(uint32_t state, bool value);
		static void set_wire_mode(bool value);

		static void clear();

	private:
		static std::map<uint32_t, bool> states;
	};
}