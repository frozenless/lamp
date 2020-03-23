#pragma once

#include "physics/ray.hpp"

namespace lamp
{
	class Camera
	{
	public:
		explicit Camera(const v2& size, float fov = 60.0f);

		void look_at(const v3& position, const v3& target);

		void perspective();
		void ortho();

		void set_size(const v2& size);
		void view(const v3& position);

		[[nodiscard]] const m4& proj() const;
		[[nodiscard]] const m4& view() const;

		[[nodiscard]] Ray screen_to_world(const v2& position) const;

	private:
		m4 _proj, _view;
		v2 _size;

		float _fov;
	};
}