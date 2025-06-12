#pragma once
#include <SDL3/SDL_keycode.h>
#include <cstdint>
#include <ostream>

namespace Oniros {

    typedef enum class KeyCode : uint16_t {
        A = SDLK_A,
        B = SDLK_B,
        C = SDLK_C,
        D = SDLK_D,
        E = SDLK_E,
        F = SDLK_F,
        G = SDLK_G,
        H = SDLK_H,
        I = SDLK_I,
        J = SDLK_J,
        K = SDLK_K,
        L = SDLK_L,
        M = SDLK_M,
        N = SDLK_N,
        O = SDLK_O,
        P = SDLK_P,
        Q = SDLK_Q,
        R = SDLK_R,
        S = SDLK_S,
        T = SDLK_T,
        U = SDLK_U,
        V = SDLK_V,
        W = SDLK_W,
        X = SDLK_X,
        Y = SDLK_Y,
        Z = SDLK_Z,

        // Number keys
        D0 = SDLK_0,
        D1 = SDLK_1,
        D2 = SDLK_2,
        D3 = SDLK_3,
        D4 = SDLK_4,
        D5 = SDLK_5,
        D6 = SDLK_6,
        D7 = SDLK_7,
        D8 = SDLK_8,
        D9 = SDLK_9,

        // Function keys
        F1 = SDLK_F1,
        F2 = SDLK_F2,
        F3 = SDLK_F3,
        F4 = SDLK_F4,
        F5 = SDLK_F5,
        F6 = SDLK_F6,
        F7 = SDLK_F7,
        F8 = SDLK_F8,
        F9 = SDLK_F9,
        F10 = SDLK_F10,
        F11 = SDLK_F11,
        F12 = SDLK_F12,
        F13 = SDLK_F13,
        F14 = SDLK_F14,
        F15 = SDLK_F15,
        F16 = SDLK_F16,
        F17 = SDLK_F17,
        F18 = SDLK_F18,
        F19 = SDLK_F19,
        F20 = SDLK_F20,
        F21 = SDLK_F21,
        F22 = SDLK_F22,
        F23 = SDLK_F23,
        F24 = SDLK_F24,

        // Control keys
        PrintScreen = SDLK_PRINTSCREEN,
        ScrollLock = SDLK_SCROLLLOCK,
        Pause = SDLK_PAUSE,
        Insert = SDLK_INSERT,
        Home = SDLK_HOME,
        PageUp = SDLK_PAGEUP,
        Delete = SDLK_DELETE,
        End = SDLK_END,
        PageDown = SDLK_PAGEDOWN,
        Right = SDLK_RIGHT,
        Left = SDLK_LEFT,
        Down = SDLK_DOWN,
        Up = SDLK_UP,

        // Modifier keys
        CapsLock = SDLK_CAPSLOCK,
        NumLock = SDLK_NUMLOCKCLEAR,

        // Punctuation keys
        Space = SDLK_SPACE,
        Apostrophe = SDLK_APOSTROPHE, /* ' */
        Comma = SDLK_COMMA,      /* , */
        Minus = SDLK_MINUS,      /* - */
        Period = SDLK_PERIOD,    /* . */
        Slash = SDLK_SLASH,      /* / */
        Semicolon = SDLK_SEMICOLON, /* ; */
        Equal = SDLK_EQUALS,        /* = */
        LeftBracket = SDLK_LEFTBRACKET,  /* [ */
        Backslash = SDLK_BACKSLASH,      /* \ */
        RightBracket = SDLK_RIGHTBRACKET,/* ] */
        GraveAccent = SDLK_GRAVE,    /* ` */

        // Additional keys
        Enter = SDLK_RETURN,
        Escape = SDLK_ESCAPE,
        Tab = SDLK_TAB,
        Backspace = SDLK_BACKSPACE,

        // Keypad
        KP0 = SDLK_KP_0,
        KP1 = SDLK_KP_1,
        KP2 = SDLK_KP_2,
        KP3 = SDLK_KP_3,
        KP4 = SDLK_KP_4,
        KP5 = SDLK_KP_5,
        KP6 = SDLK_KP_6,
        KP7 = SDLK_KP_7,
        KP8 = SDLK_KP_8,
        KP9 = SDLK_KP_9,
        KPDecimal = SDLK_KP_PERIOD,
        KPDivide = SDLK_KP_DIVIDE,
        KPMultiply = SDLK_KP_MULTIPLY,
        KPSubtract = SDLK_KP_MINUS,
        KPAdd = SDLK_KP_PLUS,
        KPEnter = SDLK_KP_ENTER,
        KPEqual = SDLK_KP_EQUALS,

        // Arrow keys
        LeftShift = SDLK_LSHIFT,
        LeftControl = SDLK_LCTRL,
        LeftAlt = SDLK_LALT,
        LeftSuper = SDLK_LGUI, // Windows key
        RightShift = SDLK_RSHIFT,
        RightControl = SDLK_RCTRL,
        RightAlt = SDLK_RALT,
        RightSuper = SDLK_RGUI, // Windows key
        Menu = SDLK_MENU

    } Key;

    inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
    {
        os << static_cast<int32_t>(keyCode);
        return os;
    }

    enum class KeyState {
        None = -1,
        Pressed,
        Held,
        Released
    };

    enum class CursorMode {
        Normal = 0,
        Hidden = 1,
        Locked = 2
    };

    typedef enum class MouseButton : uint16_t {
        Button0 = 0,
        Button1 = 1,
        Button2 = 2,
        Button3 = 3,
        Button4 = 4,
        Button5 = 5,
        Left = Button0,
        Right = Button1,
        Middle = Button2
    } Button;

    inline std::ostream& operator<<(std::ostream& os, MouseButton button)
    {
        os << static_cast<int32_t>(button);
        return os;
    }

} // namespace Hazel