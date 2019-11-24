#pragma once

namespace lamp::gl
{
	struct Shader
	{
		void compile() const noexcept;

		unsigned int id;
	};
}
