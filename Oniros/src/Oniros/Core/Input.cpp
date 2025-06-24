#include "onipch.h"

#include "Input.h"
#include "Oniros/Core/Application.h"
#include <SDL3/SDL.h>

namespace Oniros {

    bool Input::IsKeyDown(KeyCode keycode)
    {
        auto it = s_KeyData.find(keycode);
        return it != s_KeyData.end() &&
            (it->second.State == KeyState::Pressed ||
                it->second.State == KeyState::Held);
    }

    bool Input::IsKeyPressed(KeyCode keycode)
    {
        auto it = s_KeyData.find(keycode);
        return it != s_KeyData.end() &&
            it->second.State == KeyState::Pressed;
    }

    bool Input::IsKeyReleased(KeyCode keycode)
    {
        auto it = s_KeyData.find(keycode);
        return it != s_KeyData.end() &&
            it->second.State == KeyState::Released;
    }

    bool Input::IsMouseButtonDown(MouseButton button)
    {
        auto it = s_MouseData.find(button);
        return it != s_MouseData.end() &&
            (it->second.State == KeyState::Pressed ||
                it->second.State == KeyState::Held);
    }

    bool Input::IsMouseButtonPressed(MouseButton button)
    {
        auto it = s_MouseData.find(button);
        return it != s_MouseData.end() &&
            it->second.State == KeyState::Pressed;
    }

    bool Input::IsMouseButtonReleased(MouseButton button)
    {
        auto it = s_MouseData.find(button);
        return it != s_MouseData.end() &&
            it->second.State == KeyState::Released;
    }

    std::pair<float, float> Input::GetMousePosition()
    {
        float x, y;
        SDL_GetMouseState(&x, &y);
        return { static_cast<float>(x), static_cast<float>(y) };
    }

    float Input::GetMouseX()
    {
        auto [x, y] = GetMousePosition();
        return x;
    }

    float Input::GetMouseY()
    {
        auto [x, y] = GetMousePosition();
        return y;
    }

    void Input::SetCursorMode(CursorMode mode)
    {
		Application& app = Application::Get();
		


        switch (mode)
        {
        case CursorMode::Normal:
            SDL_SetWindowRelativeMouseMode((SDL_Window*)app.GetWindow().GetNativeWindow(), false);
            SDL_ShowCursor();
            break;
        case CursorMode::Hidden:
            SDL_SetWindowRelativeMouseMode((SDL_Window*)app.GetWindow().GetNativeWindow(), false);
            SDL_ShowCursor();
            break;
        case CursorMode::Locked:
            SDL_SetWindowRelativeMouseMode((SDL_Window*)app.GetWindow().GetNativeWindow(), true);
            break;
        }
    }

    CursorMode Input::GetCursorMode()
    {
        Application& app = Application::Get();

        if (SDL_GetWindowRelativeMouseMode((SDL_Window*)app.GetWindow().GetNativeWindow()))
            return CursorMode::Locked;
        else if (SDL_ShowCursor() == false)
            return CursorMode::Hidden;
        else
            return CursorMode::Normal;
    }

    // Internal state management functions

    void Input::UpdateKeyState(KeyCode key, KeyState newState)
    {
        auto& keyData = s_KeyData[key];
        keyData.Key = key;
        keyData.PreviousState = keyData.State;
        keyData.State = newState;
    }

    void Input::UpdateMouseButtonState(MouseButton button, KeyState newState)
    {
        auto& buttonData = s_MouseData[button];
        buttonData.Button = button;
        buttonData.PreviousState = buttonData.State;
        buttonData.State = newState;
    }

    void Input::TransitionKeyStates()
    {
        for (auto& [key, keyData] : s_KeyData)
        {
            if (keyData.State == KeyState::Pressed)
                UpdateKeyState(key, KeyState::Held);
        }
    }

    void Input::TransitionMouseButtonStates()
    {
        for (auto& [button, buttonData] : s_MouseData)
        {
            if (buttonData.State == KeyState::Pressed)
                UpdateMouseButtonState(button, KeyState::Held);
        }
    }

    void Input::ResetInputStates()
    {
        for (auto it = s_KeyData.begin(); it != s_KeyData.end(); )
        {
            if (it->second.State == KeyState::Released)
                it = s_KeyData.erase(it);
            else
                ++it;
        }

        for (auto it = s_MouseData.begin(); it != s_MouseData.end(); )
        {
            if (it->second.State == KeyState::Released)
                it = s_MouseData.erase(it);
            else
                ++it;
        }
    }

}