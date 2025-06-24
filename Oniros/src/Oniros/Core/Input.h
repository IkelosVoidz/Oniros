#pragma once

#include "Oniros/Events/KeyCodes.h"
#include <map>


namespace Oniros {
	 
	struct KeyData
	{
		KeyCode Key;
		KeyState State = KeyState::None;
		KeyState PreviousState = KeyState::None;
	};

	struct ButtonData
	{
		MouseButton Button;
		KeyState State = KeyState::None;
		KeyState PreviousState = KeyState::None;
	};
	
	class Input
	{
	public:

		static bool IsKeyDown(KeyCode keycode); //Pressed or Held
		static bool IsMouseButtonDown(MouseButton button); //Pressed or Held

		static bool IsKeyPressed(KeyCode keycode); //Pressed this frame
		static bool IsMouseButtonPressed(MouseButton button); //Pressed this frame
		static bool IsKeyReleased(KeyCode keycode); //Released this frame
		static bool IsMouseButtonReleased(MouseButton button); //Released this frame

		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();


		static void SetCursorMode(CursorMode mode); // 0: Normal, 1: Hidden, 2: Disabled
		static CursorMode GetCursorMode(); 
	
		
		static void UpdateKeyState(KeyCode keycode, KeyState newState);
		static void UpdateMouseButtonState(MouseButton button, KeyState newState);
		
		static void TransitionKeyStates();
		static void TransitionMouseButtonStates();
		static void ResetInputStates();


	private:

		inline static std::map<KeyCode, KeyData> s_KeyData;
		inline static std::map<MouseButton, ButtonData> s_MouseData;

	};
} 