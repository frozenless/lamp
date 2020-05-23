#include "buffer.inl"

namespace lamp::gl
{
	Buffer::Buffer(const uint32_t target, const uint32_t usage)
		: Object(Type::Buffer)
		, _target(target)
		, _usage(usage)
	{
	}

	void Buffer::bind(const uint32_t index) const noexcept
	{
		assert(_target == GL_UNIFORM_BUFFER);

		glBindBufferBase(_target, index, _id);
	}

	void Buffer::bind() const noexcept
	{
		glBindBuffer(_target, _id);
	}

	void Buffer::create() noexcept
	{
		glCreateBuffers(1, &_id);
	}

	void Buffer::release() noexcept
	{
		glDeleteBuffers(1, &_id);
	}
}