#pragma once

#include "layout.hpp"
#include "types.hpp"

namespace lamp
{
	class Assets
	{
	public:
		static gl::shader_ptr  create(const std::string_view& path, u32 type);
		static gl::texture_ptr create(const std::string_view& path, bool mipmap, bool flip);
		static gl::program_ptr create(const gl::shader_ptr& vertex, const gl::shader_ptr& fragment);

		template<typename T, typename U> static gl::mesh_ptr create(const std::vector<T>& vertices, const std::vector<U>& indices, const Layout& layout, u32 primitive, u32 type, u32 usage);
		template<typename T> static gl::buffer_ptr create(u32 type, const std::vector<T>& info, u32 usage) noexcept;

		static gl::mesh_ptr create(const v2& size);
	};
}
