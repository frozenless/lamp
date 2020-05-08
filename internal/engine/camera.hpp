#include "physics/ray.hpp"

namespace lamp
{
	class Camera
	{
	public:
	    enum class Type
        {
	        Perspective,
            Orthographic
        };

	    Camera();
		Camera(Type type, const v2& size, float fov);

		void look(const v3& position, const v3& target);
		void update();

        void view(const v3& position);
        void size(const v2& size);

		void fov(float value);

        [[nodiscard]] Ray to_world(const v2& position) const;

		[[nodiscard]] const m4& proj() const;
		[[nodiscard]] const m4& view() const;

	private:
		m4 _proj, _view;
		v2 _size;

        float _fov = 60.0f;
        Type  _type;
    };
}