#pragma once

#include "types.hpp"

namespace lamp::gl
{
	struct Object
	{
		enum class Type {
			Shader,
			Texture,
			Mesh
		};

		explicit Object(Type type);
		virtual  void bind() const noexcept = 0;

		Type   type;
		handle id;
	};
}
