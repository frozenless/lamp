#pragma once

namespace lamp::gl
{
	struct Attribute
	{
		void enable() const noexcept;

		int count;
		int index;
		int offset;
	};
}
