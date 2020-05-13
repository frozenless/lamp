#pragma once

#include "engine/components/light.hpp"
#include "engine/material.hpp"

struct GLFWwindow;

namespace lamp
{
	class Editor
	{
	public:
		static void init(GLFWwindow* window);
		static void release();

        static void draw(const std::shared_ptr<Material>& material);
        static void draw(components::light& light);

		static void begin();
		static void end();
	};
}
