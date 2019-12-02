#pragma once

#include "model.hpp"

namespace lamp
{
	void draw_model(const std::shared_ptr <Model> &model);
	void screen_to_world_ray(const v2& mouse, const v2& size, const m4& inv, v3& origin, v3& direction);
}

