#include "editor.hpp"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <glm/gtc/type_ptr.hpp>

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

	void Editor::draw(components::light& light)
	{
		ImGui::Begin("Light", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

		ImGui::InputFloat3("Position", glm::value_ptr(light.position), 3);
		ImGui::ColorEdit3( "Color",    glm::value_ptr(light.color));
		ImGui::InputFloat("Ambient",   &light.ambient,  0.1f);
		ImGui::InputFloat("Diffuse",   &light.diffuse,  0.1f);
		ImGui::InputFloat("Specular",  &light.specular, 0.1f);

		ImGui::End();
	}

	void Editor::draw(const char* title, const material_ptr& material)
	{
		ImGui::Begin(title, nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
		ImGui::ColorEdit3("Color",     glm::value_ptr(material->color));
		ImGui::InputFloat("Shininess", &material->shininess,  1.0f);

		if (material->diffuse)
		{
			ImGui::Image(reinterpret_cast<void*>(material->diffuse->id), ImVec2(70.0f, 70.0f));
		}

		ImGui::End();
	}
}