#pragma once

#include "object.hpp"

namespace lamp::gl
{
	class Texture : public Object
	{
	public:
		explicit Texture(uint32_t target);

		void create()  noexcept final;
		void release() noexcept final;

		void bind() const noexcept final;

		void set_data(const unsigned char* data);
		void set_sampler(uint32_t min_filter, uint32_t mag_filter) const;

		int32_t width, height;
		int32_t channels;

	private:
		[[nodiscard]]
		uint32_t _get_format() const noexcept;
		uint32_t _target;
	};
}
