#pragma once

#include "types.hpp"

namespace lamp::gl
{
	struct Texture
	{
		explicit Texture(u32 target);

		void bind()   const noexcept;
		void set_data(const unsigned char* data);

		int channels;
		int width, height;

		handle id;

	private:
		[[nodiscard]]
		u32 _get_format() const noexcept;
		u32 _target;
	};
}
