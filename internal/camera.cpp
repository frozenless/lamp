#include "camera.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace lamp
{
	void Camera::update_view()
	{
		view = glm::translate(m4(1.0f), v3(0.0f, 0.0f, -3.5f));
	}

	void Camera::update_proj(const v2& size)
	{
		proj = glm::perspective(glm::radians(60.0f), size.x / size.y, 0.1f, 100.0f);
	}
}