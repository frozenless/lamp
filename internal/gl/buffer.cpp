#include "buffer.inl"

namespace lamp::gl
{
	Buffer::Buffer(const u32 target, const u32 usage)
		: _target(target)
		, _usage(usage)
		, id(0)
	{
	}

	void Buffer::bind() const
	{
		glBindBuffer(_target, id);
	}
}