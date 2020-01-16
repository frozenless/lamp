#include "camera.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace lamp
{
	Camera::Camera(const v2& size, const f32 fov)
		: _view(1.0f)
		, _fov(fov)
		, _size(size)
	{
	}

	void Camera::perspective()
	{
		_projection = glm::perspective(glm::radians(_fov), _size.x / _size.y, 0.1f, 100.0f);
	}

	void Camera::otho()
	{
		_projection = glm::ortho(0.0f, _size.x, 0.0f, _size.y, 1.0f, -1.0f);
	}

	void Camera::look_at(const v3& position, const v3& target)
	{
		_view = glm::lookAt(position, target, lamp::v3(0.0f, 1.0f, 0.0f));
	}

	void Camera::view(const v3& position)
	{
		_view = glm::translate(m4(1.0f), position);
	}

	const m4& Camera::projection() const
	{
		return _projection;
	}

	const m4& Camera::view() const
	{
		return _view;
	}

	Ray Camera::screen_to_world(const v2& position, const m4& inv)
	{
		const f32 x = (position.x / _size.x - 0.5f) * 2.0f;
		const f32 y = (position.y / _size.y - 0.5f) * 2.0f;

		v4 start = inv * v4(x, y,-1.0f, 1.0f); start /= start.w;
		v4 end   = inv * v4(x, y, 0.0f, 1.0f);   end /= end.w;

		return Ray(start, glm::normalize(end - start));
	}

	void Camera::set_size(const v2& size)
	{
		_size = size;
	}
}