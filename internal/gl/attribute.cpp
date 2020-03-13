#include "attribute.hpp"

namespace lamp::gl
{
	Attribute::Attribute(const u32 count, const u32 type, const u32 offset) noexcept
		: count(count)
		, type(type)
		, offset(offset)
	{
	}
}