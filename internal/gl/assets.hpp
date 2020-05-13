#include "layout.hpp"
#include "types.hpp"

namespace lamp
{
	class Assets
	{
	public:
		static gl::shader_ptr  create(const char* path, uint32_t type);
		static gl::texture_ptr create(const char* path, bool mipmap, bool flip);
		static gl::program_ptr create(const gl::shader_ptr& vertex, const gl::shader_ptr& fragment);

		static mesh_ptr create(const v2& size);
        static mesh_ptr create(const gl::Layout& layout, uint32_t primitive, uint32_t usage);

        static gl::buffer_ptr create(uint32_t type, uint32_t usage, uint32_t index);

        template<typename T, std::size_t S, typename U, std::size_t V> static mesh_ptr create(const std::array<T, S>& vertices, const std::array<U, V>& indices, const gl::Layout& layout, uint32_t primitive, uint32_t usage);
        template<typename T, typename U> static mesh_ptr create(const std::vector<T>& vertices, const std::vector<U>& indices, const gl::Layout& layout, uint32_t primitive, uint32_t usage);
        template<typename T, typename U> static mesh_ptr create(const std::pair<const T*, size_t>& vertices, const std::pair<const U*, size_t>& indices, const gl::Layout& layout, uint32_t primitive, uint32_t usage);

        template<typename T>   static gl::buffer_ptr create(uint32_t type, const std::pair<const T*, size_t>& data, uint32_t usage);
	};
}
