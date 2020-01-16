#pragma once

#include "types.hpp"

namespace lamp::gl
{
	class Texture
	{
	public:
		explicit Texture(u32 target);

		void bind()   const noexcept;

		void set_data(const unsigned char* data);
		void set_sampler(u32 min_filter, u32 mag_filter) const;

		int width, height;
		int channels;

		handle id;

	private:
		[[nodiscard]]
		u32 _get_format() const noexcept;
		u32 _target;
	};
}
