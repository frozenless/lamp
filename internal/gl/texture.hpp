#pragma once

#include "object.hpp"

namespace lamp::gl
{
	class Texture : public Object
	{
	public:
		explicit Texture(u32 target);

		void create()  noexcept final;
		void release() noexcept final;

		void bind() const noexcept final;

		void set_data(const unsigned char* data);
		void set_sampler(u32 min_filter, u32 mag_filter) const;

		int width, height;
		int channels;

	private:
		[[nodiscard]]
		u32 _get_format() const noexcept;
		u32 _target;
	};
}
