#include "editor.hpp"

#include "gl/texture.hpp"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <glm/gtc/type_ptr.hpp>

namespace lamp::ui
{
    constexpr int32_t panel_flag = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoNav;
    constexpr int32_t color_flag = ImGuiColorEditFlags_NoOptions | ImGuiColorEditFlags_NoTooltip;

	void Editor::init(GLFWwindow* window)
	{
		ImGui::CreateContext();

		//ImGuiIO& io = ImGui::GetIO();
		ImGui::StyleColorsDark();

		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 450 core");
	}

	void Editor::begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();

		ImGui::NewFrame();
	}

	void Editor::end()
	{
		ImGui::Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void Editor::release()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();

		ImGui::DestroyContext();
	}

	void Editor::draw(entityx::ComponentHandle<components::light> light)
	{
		ImGui::Begin("Light", nullptr, panel_flag);

		ImGui::InputFloat3("Position", glm::value_ptr(light->position));

		ImGui::ColorEdit3("Color",    static_cast<float*>(light->color), color_flag);
		ImGui::InputFloat("Ambient",  &light->ambient,  0.1f);
		ImGui::InputFloat("Diffuse",  &light->diffuse,  0.1f);
		ImGui::InputFloat("Specular", &light->specular, 0.1f);

		ImGui::End();
	}

	void Editor::draw(const std::shared_ptr<Material>& material)
	{
		ImGui::Begin("Material", nullptr, panel_flag);

		ImGui::ColorEdit3("Color",     static_cast<float*>(material->color), color_flag);
		ImGui::InputFloat("Shininess", &material->shininess, 1.0f);

		if (material->diffuse)
		{
			ImGui::Image(reinterpret_cast<void*>(material->diffuse->id), ImVec2(70.0f, 70.0f));
		}

		ImGui::End();
	}
}