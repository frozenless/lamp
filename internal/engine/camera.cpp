#include "camera.hpp"

namespace lamp
{
    /*
	void Camera::look(const v3& position, const v3& target)
	{
		constexpr v3 up(0.0f, 1.0f, 0.0f);

		_view = glm::lookAt(position, target, up);
	}

	Ray Camera::to_world(const v2& position) const
	{
		const m4 inv = glm::inverse(_proj * _view);

		const float x =  (position.x / size.x - 0.5f) * 2.0f;
		const float y = -(position.y / size.y - 0.5f) * 2.0f;

		v4 start = inv * v4(x, y,-1.0f, 1.0f); start /= start.w;
		v4 end   = inv * v4(x, y, 0.0f, 1.0f);   end /= end.w;

		return Ray(start, glm::normalize(end - start));
	}*/
}