#include "transform.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace lamp
{
	void Transform::from(const v3& p, f32 s)
	{
		position = p;
		scale    = s;

		update();
	}

	void Transform::update()
	{
		world = glm::translate(m4(1.0f), position);
		world = glm::scale(world, v3(scale));
	}
}