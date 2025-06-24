#include "VoxelApplication.h"

void VoxelApplication::OnImGuiRender()
{
	ImGui::Begin("Test");
	ImGui::Text("Hello, Oniros!");
	ImGui::End();
}

void VoxelApplication::OnUpdate(float deltaTime)
{
	if(Oniros::Input::IsKeyPressed(Oniros::KeyCode::Space)){
		ONI_TRACE("Space key pressed just this frame");
	};

	if (Oniros::Input::IsKeyDown(Oniros::KeyCode::Space)) {
		ONI_TRACE("Space key is being held down");
	};

	if (Oniros::Input::IsKeyReleased(Oniros::KeyCode::Space)) {
		ONI_TRACE("Space key released this frame");
	}

	if (Oniros::Input::IsMouseButtonPressed(Oniros::MouseButton::ButtonLeft)) {
		ONI_TRACE("Left mouse button pressed this frame");
	}

	if (Oniros::Input::IsMouseButtonDown(Oniros::MouseButton::ButtonLeft)) {
		ONI_TRACE("Left mouse button is being held down");
	}

	if (Oniros::Input::IsMouseButtonReleased(Oniros::MouseButton::ButtonLeft)) {
		ONI_TRACE("Left mouse button released this frame");
	}
}
