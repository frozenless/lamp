#include "model.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace lamp
{
	Model::Model(const v3& position, const f32 scale) noexcept
		: position(position)
		, scale(scale)
		, world(1.0f)
		, color(1.0f)
	{
	}

	void Model::update()
	{
		world = glm::translate(m4(1.0f), position);
		world = glm::scale(world, v3(scale));
	}
}