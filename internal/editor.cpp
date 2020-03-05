#include "editor.hpp"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <glm/gtc/type_ptr.hpp>

#include "common/config.hpp"
#include "engine/material.hpp"

#include "gl/texture.hpp"

namespace lamp
{
	void Editor::init(GLFWwindow* window)
	{
		ImGui::CreateContext();

		//ImGuiIO& io = ImGui::GetIO();
		ImGui::StyleColorsDark();

		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init(versions::glsl);
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

	void Editor::draw(Light& light)
	{
		ImGui::Begin("Light");

		ImGui::InputFloat3("Position", glm::value_ptr(light.position), 3);
		ImGui::ColorEdit3( "Color",    glm::value_ptr(light.color));
		ImGui::InputFloat("Diffuse", &light.diffuse, 1);
		ImGui::InputFloat("Ambient", &light.ambient, 1);

		ImGui::End();
	}

	void Editor::draw(const char* title, const material_ptr& material)
	{
		ImGui::Begin(title);
		ImGui::ColorEdit3("Color", glm::value_ptr(material->color));

		if (material->texture)
		{
			ImGui::Image(reinterpret_cast<void *>(material->texture->id), ImVec2(70.0f, 70.0f));
		}

		ImGui::End();
	}
}