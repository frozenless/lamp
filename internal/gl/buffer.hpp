#pragma once

#include "types.hpp"
#include <vector>

namespace lamp::gl
{
	class Buffer
	{
	public:
		Buffer(u32 target, u32 usage);

		void bind() const;

		template <typename T> void set_data(const std::vector<T>& info);

		handle id;

	private:
		u32 _target;
		u32 _usage;
	};
}