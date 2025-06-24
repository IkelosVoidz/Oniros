#pragma once

#include <imgui.h>
#include <backends/imgui_impl_sdl3.h>
#include <backends/imgui_impl_opengl3.h>


namespace Oniros {

	class ImGuiSystem
	{
	public:
		ImGuiSystem();
		~ImGuiSystem();

		void SetDarkThemeColors();

		void Init();
		void Shutdown();

		void OnUpdate(float deltaTime);

		// Begin and End are used to start and end the ImGui frame
		void Begin();
		void End();

	};
}


