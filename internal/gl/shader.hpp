#pragma once

#include "types.hpp"

#include <vector>

namespace lamp::gl
{
	struct Shader
	{
		Shader();

		void create(u32 type);

		void compile() const noexcept;
		void release() const noexcept;

		void set_source(const std::vector<const char*>& sources);

		#ifndef NDEBUG
		void status();
		#endif

		handle id;
	};
}
