#pragma once

#include "physics/ray.hpp"

namespace lamp
{
	class Camera
	{
	public:
		explicit Camera(const v2& size, f32 fov = 60.0f);

		void look_at(const v3& position, const v3& target);

		void perspective();
		void otho();

		void set_size(const v2& size);
		void view(const v3& position);

		const m4& projection() const;
		const m4& view()       const;

		Ray screen_to_world(const v2& position, const m4& inv);

	private:
		v2 _size;
		m4 _projection, _view;

		f32 _fov;
	};
}