#pragma once

#include "types.hpp"

namespace lamp::gl
{
	class Object
	{
	public:
		enum class Type
		{
			Shader,
			Texture,
			Buffer,
            VertexArray
		};

		explicit Object(Type type);

		virtual void create()  noexcept = 0;
		virtual void release() noexcept = 0;

		virtual void bind() const noexcept = 0;

        [[nodiscard]] Type type() const;
        [[nodiscard]] Id   id() const;

    protected:
        Type _type;
		Id   _id;
	};
}
