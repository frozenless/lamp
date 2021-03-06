#pragma once

#include "engine/components/light.hpp"

struct GLFWwindow;

namespace lamp
{
	class Editor
	{
	public:
		static void init(GLFWwindow* window);
		static void release();

		static void draw(components::light& light);
		static void draw(const material_ptr& material);

		static void begin();
		static void end();
	};
}
