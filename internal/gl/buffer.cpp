#include "buffer.inl"

namespace lamp::gl
{
	Buffer::Buffer(const uint32_t target, const uint32_t usage)
		: Object(Type::Buffer)
		, _target(target)
		, _usage(usage)
	{
	}

	void Buffer::bind_base(const uint32_t index) const
	{
		assert(_target == GL_UNIFORM_BUFFER);

		glBindBufferBase(_target, index, id);
	}

	void Buffer::bind() const noexcept
	{
		glBindBuffer(_target, id);
	}

	void Buffer::create() noexcept
	{
		glCreateBuffers(1, &id);
	}

	void Buffer::release() noexcept
	{
		glDeleteBuffers(1, &id);
	}
}