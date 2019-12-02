#include "engine.hpp"

namespace lamp
{
	void draw_model(const std::shared_ptr<Model>& model)
	{
		gl::Program::uniform(2, model->world);
		gl::Program::uniform(3, model->color);

		if (const meshPtr& mesh = model->mesh; mesh)
		{
			mesh->bind();
			mesh->draw();
		}
	}

	void screen_to_world_ray(const v2& mouse, const v2& size, const m4& inv, v3& origin, v3& direction)
	{
		const f32 a = (mouse.x / size.x - 0.5f) * 2.0f;
		const f32 b = (mouse.y / size.y - 0.5f) * 2.0f;

		v4 start = inv * v4(a, b,-1.0f, 1.0f); start /= start.w;
		v4 end   = inv * v4(a, b, 0.0f, 1.0f);   end /= end.w;

		direction = glm::normalize(end - start);
		origin    = start;
	}
}