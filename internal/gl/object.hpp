#pragma once

#include "types.hpp"

namespace lamp::gl
{
	struct Object
	{
		enum class Type
		{
			Shader,
			Texture,
			Buffer,
			Mesh
		};

		explicit Object(Type type);

		virtual void create()  noexcept = 0;
		virtual void release() noexcept = 0;

		virtual void bind() const noexcept = 0;

		Type type;
		ID   id;
	};
}
