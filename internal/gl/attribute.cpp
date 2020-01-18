#include "attribute.hpp"

namespace lamp::gl
{
	Attribute::Attribute(const int count, const u32 type, const int offset)
		: count(count)
		, offset(offset)
		, type(type)
	{
	}
}