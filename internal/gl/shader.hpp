#pragma once

#include "types.hpp"

namespace lamp::gl
{
	struct Shader
	{
		Shader();

		void create(u32 type);

		void compile() const noexcept;
		void release() const noexcept;

		void set_source(const char* source);

		#ifndef NDEBUG
		void status();
		#endif

		ID id;
	};
}
