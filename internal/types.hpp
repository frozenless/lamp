#pragma once

#include "utils/forward.hpp"

#include <glm/glm.hpp>
#include <memory>

namespace lamp
{
	using u8  = glm::u8;
	using u16 = glm::u16;
	using u32 = glm::u32;

	using f32 = glm::f32;
	using f64 = glm::f64;

	using iv2 = glm::ivec2;
	using iv4 = glm::ivec4;

	using v2 = glm::vec2;
	using v3 = glm::vec3;
	using v4 = glm::vec4;

	using m4 = glm::mat4;

	using rgb  = glm::vec3;
	using rgba = glm::vec4;

	using material_ptr  = std::shared_ptr<Material>;
	using transform_ptr = std::shared_ptr<Transform>;

	namespace gl
	{
		using buffer_ptr = std::shared_ptr<Buffer>;
		using mesh_ptr   = std::shared_ptr<Mesh>;
		using shader_ptr = std::shared_ptr<Shader>;

		using program_ptr = std::shared_ptr<Program>;
		using texture_ptr = std::shared_ptr<Texture>;

		using handle = u32;
	}
}