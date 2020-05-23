#include "attribute.hpp"

namespace lamp::gl::vertex
{
	attribute::attribute(const uint32_t count, const uint32_t type, const uint32_t offset) noexcept
		: count(count)
		, type(type)
		, offset(offset)
	{
	}
}