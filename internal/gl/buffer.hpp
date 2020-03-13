#pragma once

#include "object.hpp"

namespace lamp::gl
{
	class Buffer : public Object
	{
	public:
		Buffer(u32 target, u32 usage);

		void create()  noexcept final;
		void release() noexcept final;

		template <typename T> void set_data(const std::vector<T>& buffer) const;
			void bind_base(u32 index) const;

	private:
		void bind() const noexcept final;

		u32 _target;
		u32 _usage;
	};
}