#include "camera.hpp"

namespace lamp
{
	Camera::Camera(const v2& size, const float fov)
		: _view(glm::identity<m4>())
		, _size(size)
		, _fov(fov)
	{
	}

	void Camera::perspective()
	{
        const float aspect = _size.x / _size.y;

		_proj = glm::perspective(glm::radians(_fov), aspect, 0.1f, 100.0f);
	}

	void Camera::ortho()
	{
		_proj = glm::ortho(0.0f, _size.x, 0.0f, _size.y, 1.0f, -1.0f);
	}

	void Camera::look_at(const v3& position, const v3& target)
	{
		constexpr v3 up(0.0f, 1.0f, 0.0f);

		_view = glm::lookAt(position, target, up);
	}

	void Camera::view(const v3& position)
	{
		_view = glm::translate(glm::identity<m4>(), position);
	}

	const m4& Camera::proj() const
	{
		return _proj;
	}

	const m4& Camera::view() const
	{
		return _view;
	}

	Ray Camera::screen_to_world(const v2& position) const
	{
		const m4 inv  = glm::inverse(_proj * _view);

		const float x =  (position.x / _size.x - 0.5f) * 2.0f;
		const float y = -(position.y / _size.y - 0.5f) * 2.0f;

		v4 start = inv * v4(x, y,-1.0f, 1.0f); start /= start.w;
		v4 end   = inv * v4(x, y, 0.0f, 1.0f);   end /= end.w;

		return Ray(start, glm::normalize(end - start));
	}

	void Camera::size(const v2& size)
	{
		_size = size;
	}
}