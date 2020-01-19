#pragma once

#include "types.hpp"

namespace lamp::gl
{
	class Buffer
	{
	public:
		Buffer(u32 target, u32 usage);

		void bind() const;
		void bind_base(u32 index) const;

		template <typename T> void set_data(const std::vector<T>& info);

		handle id;

	private:
		u32 _target;
		u32 _usage;
	};
}