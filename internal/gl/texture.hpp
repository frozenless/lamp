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

		void data(const uint8_t* data);
		void sampler(uint32_t min_filter, uint32_t mag_filter) const;

		static void activate(uint32_t index = 0);

		int32_t width, height;
		int32_t channels;

	private:
		[[nodiscard]]
		uint32_t _format() const noexcept;
		uint32_t _target;
	};
}
