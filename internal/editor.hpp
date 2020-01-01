#pragma once

struct GLFWwindow;

namespace lamp
{
	class Editor
	{
	public:
		static void init(GLFWwindow *window);
		static void release();

		static void begin_draw();
		static void end_draw();
	};
}
