#include "object.hpp"

namespace lamp::gl
{
	class Buffer : public Object
	{
	public:
		Buffer(uint32_t target, uint32_t usage);

		~Buffer() = default;

		void create()  noexcept final;
		void release() noexcept final;

		void bind(uint32_t index) const noexcept;

		template <typename T, std::size_t S> void data(const std::array<T, S>& buffer) const noexcept;
        template <typename T> void data(const std::pair<const T*, size_t>& buffer)    const noexcept;

        template <typename T> void data(const std::vector<T>& buffer) const noexcept;

	private:
		void bind() const noexcept final;

		uint32_t _target;
		uint32_t _usage;
	};
}