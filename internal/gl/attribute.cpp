#include "attribute.hpp"

namespace lamp::gl
{
	Attribute::Attribute(int index, int count, u32 type, int offset)
		: count(count)
		, index(index)
		, offset(offset)
		, type(type)
	{
	}
}