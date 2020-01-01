#pragma once

#include "engine/transform.hpp"
#include "engine/material.hpp"

#include <memory>

namespace lamp
{
	using material_ptr = std::shared_ptr<Material>;
	using transform_ptr = std::shared_ptr<Transform>;

	void draw_model(const transform_ptr& transform, const gl::mesh_ptr& mesh, const material_ptr& material);
	void screen_to_world_ray(const v2& mouse, const v2& size, const m4& inv, v3& origin, v3& direction);
}

