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
}