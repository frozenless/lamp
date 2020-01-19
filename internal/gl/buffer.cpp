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

	void Buffer::bind_buffer_base(const u32 index) const
	{
		assert(_target == GL_UNIFORM_BUFFER);

		glBindBufferBase(_target, index, id);
	}
}