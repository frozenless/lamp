#pragma once

#include "common/fwd.hpp"
#include "common/dependencies.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace lamp
{
	using iv2 = glm::ivec2;
	using iv4 = glm::ivec4;

	using v2 = glm::vec2;
	using v3 = glm::vec3;
	using v4 = glm::vec4;

	using m4   = glm::mat4;
	using quat = glm::quat;

	using rgba = glm::vec4;

	using material_ptr  = std::shared_ptr<Material>;

	namespace gl
	{
		using object_ptr = std::shared_ptr<Object>;
		using buffer_ptr = std::shared_ptr<Buffer>;
		using mesh_ptr   = std::shared_ptr<Mesh>;
		using shader_ptr = std::shared_ptr<Shader>;

		using program_ptr = std::shared_ptr<Program>;
		using texture_ptr = std::shared_ptr<Texture>;

		using ID = uint32_t;
	}
}