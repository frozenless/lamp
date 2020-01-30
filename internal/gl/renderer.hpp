#pragma once

#include "types.hpp"

namespace lamp::gl
{
	class Renderer
	{
	public:
		enum class Bindings
		{
			Shader
		};

		static void init();
		static void init_blending();

		static bool bind(Bindings type, handle id);

		static void set_viewport(const iv4& size);
		static void set_clear_color(const rgb& color);

		static void set_shader(const program_ptr& shader);
		static void set_wire_mode(bool value);

		static void enable(u32 value);
		static void disable(u32 value);

		static void clear();

	private:
		static std::map<Bindings, handle> _bindings;
		static handle _shader;
	};
}