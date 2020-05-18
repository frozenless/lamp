#pragma once

#include "types.hpp"
#include "math/rgb.hpp"

namespace lamp::gl
{
	class Renderer
	{
	public:
		static void init();
		static void init_blending();

		static void viewport(const iv4& size);
		static void clear(const math::rgb& rgb);

		static void state(uint32_t state, bool value);
		static void wire_mode(bool value);

		static void clear();

	private:
		static std::map<uint32_t, bool> states;
	};
}