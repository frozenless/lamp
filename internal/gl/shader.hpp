#pragma once

#include "util.hpp"

namespace lamp::gl
{
	struct Shader
	{
		void compile() const noexcept;
		void release() const noexcept;

		u32 id;
	};
}
