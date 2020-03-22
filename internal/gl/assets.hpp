#pragma once

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

		template<typename T, typename U> static gl::mesh_ptr   create(const std::vector<T>& vertices, const std::vector<U>& indices, const gl::Layout& layout, uint32_t primitive, uint32_t type, uint32_t usage);
		template<typename T>   static gl::buffer_ptr create(uint32_t type, const std::vector<T>& info, uint32_t usage) noexcept;

		static gl::mesh_ptr create(const v2& size);
	};
}
