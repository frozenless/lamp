#pragma once

namespace lamp::gl
{
	struct Attribute
	{
		void update(int vertex_size) const noexcept;
		void enable() const noexcept;

		int index;
		int count;
		int offset;
	};
}
