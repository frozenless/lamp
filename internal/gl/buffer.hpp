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

		void bind_base(uint32_t index) const;

		template <typename T, std::size_t S> void set_data(const std::array<T, S>& buffer) const;
		template <typename T> void set_data(const std::vector<T>&   buffer) const;
		template <typename T> void set_data(const T* buffer, size_t size)   const;

	private:
		void bind() const noexcept final;

		uint32_t _target;
		uint32_t _usage;
	};
}