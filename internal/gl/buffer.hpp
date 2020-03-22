#pragma once

#include "object.hpp"

namespace lamp::gl
{
	class Buffer : public Object
	{
	public:
		Buffer(uint32_t target, uint32_t usage);

		void create()  noexcept final;
		void release() noexcept final;

		template <typename T> void set_data(const std::vector<T>& buffer) const;
			void bind_base(uint32_t index) const;

	private:
		void bind() const noexcept final;

		uint32_t _target;
		uint32_t _usage;
	};
}