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

		void set_source(const char* source) const;

		#ifndef NDEBUG
		void status() const;
		#endif

		ID id;
	};
}
