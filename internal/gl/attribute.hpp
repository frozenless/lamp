#pragma once

namespace lamp::gl
{
	struct Attribute
	{
		Attribute(int index, int count, int offset);

		void enable() const noexcept;

		int index;
		int count;
		int offset;
	};
}
