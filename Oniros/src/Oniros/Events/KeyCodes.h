#pragma once

#include <cstdint>
#include <ostream>

namespace Oniros {

    typedef enum class KeyCode : int32_t {
        
		//From SDL_keycode.h

        A = 97,  // 0x61, 'a'
        B = 98,  // 0x62, 'b'
        C = 99,  // 0x63, 'c'
        D = 100, // 0x64, 'd'
        E = 101, // 0x65, 'e'
        F = 102, // 0x66, 'f'
        G = 103, // 0x67, 'g'
        H = 104, // 0x68, 'h'
        I = 105, // 0x69, 'i'
        J = 106, // 0x6A, 'j'
        K = 107, // 0x6B, 'k'
        L = 108, // 0x6C, 'l'
        M = 109, // 0x6D, 'm'
        N = 110, // 0x6E, 'n'
        O = 111, // 0x6F, 'o'
        P = 112, // 0x70, 'p'
        Q = 113, // 0x71, 'q'
        R = 114, // 0x72, 'r'
        S = 115, // 0x73, 's'
        T = 116, // 0x74, 't'
        U = 117, // 0x75, 'u'
        V = 118, // 0x76, 'v'
        W = 119, // 0x77, 'w'
        X = 120, // 0x78, 'x'
        Y = 121, // 0x79, 'y'
        Z = 122, // 0x7A, 'z'

        // Number keys (using ASCII values)
        D0 = 48, // 0x30, '0'
        D1 = 49, // 0x31, '1'
        D2 = 50, // 0x32, '2'
        D3 = 51, // 0x33, '3'
        D4 = 52, // 0x34, '4'
        D5 = 53, // 0x35, '5'
        D6 = 54, // 0x36, '6'
        D7 = 55, // 0x37, '7'
        D8 = 56, // 0x38, '8'
        D9 = 57, // 0x39, '9'

        // Function keys
        F1 = 1073741882, // 0x4000003A
        F2 = 1073741883, // 0x4000003B
        F3 = 1073741884, // 0x4000003C
        F4 = 1073741885, // 0x4000003D
        F5 = 1073741886, // 0x4000003E
        F6 = 1073741887, // 0x4000003F
        F7 = 1073741888, // 0x40000040
        F8 = 1073741889, // 0x40000041
        F9 = 1073741890, // 0x40000042
        F10 = 1073741891, // 0x40000043
        F11 = 1073741892, // 0x40000044
        F12 = 1073741893, // 0x40000045
        F13 = 1073741928, // 0x40000068
        F14 = 1073741929, // 0x40000069
        F15 = 1073741930, // 0x4000006A
        F16 = 1073741931, // 0x4000006B
        F17 = 1073741932, // 0x4000006C
        F18 = 1073741933, // 0x4000006D
        F19 = 1073741934, // 0x4000006E
        F20 = 1073741935, // 0x4000006F
        F21 = 1073741936, // 0x40000070
        F22 = 1073741937, // 0x40000071
        F23 = 1073741938, // 0x40000072
        F24 = 1073741939, // 0x40000073

        // Control keys
        PrintScreen = 1073741894, // 0x40000046
        ScrollLock = 1073741895, // 0x40000047
        Pause = 1073741896, // 0x40000048
        Insert = 1073741897, // 0x40000049
        Home = 1073741898, // 0x4000004A
        PageUp = 1073741899, // 0x4000004B
        Delete = 127,        // 0x7F
        End = 1073741901, // 0x4000004D
        PageDown = 1073741902, // 0x4000004E
        Right = 1073741903, // 0x4000004F
        Left = 1073741904, // 0x40000050
        Down = 1073741905, // 0x40000051
        Up = 1073741906, // 0x40000052

        // Modifier keys
        CapsLock = 1073741881, // 0x40000039
        NumLock = 1073741907, // 0x40000053

        // Punctuation keys
        Space = 32,  // 0x20, ' '
        Apostrophe = 39,  // 0x27, '\''
        Comma = 44,  // 0x2C, ','
        Minus = 45,  // 0x2D, '-'
        Period = 46,  // 0x2E, '.'
        Slash = 47,  // 0x2F, '/'
        Semicolon = 59,  // 0x3B, ';'
        Equal = 61,  // 0x3D, '='
        LeftBracket = 91,  // 0x5B, '['
        Backslash = 92,  // 0x5C, '\\'
        RightBracket = 93,  // 0x5D, ']'
        GraveAccent = 96,  // 0x60, '`'

        // Additional keys
        Enter = 13,           // 0x0D, '\r'
        Escape = 27,           // 0x1B, '\x1B'
        Tab = 9,            // 0x09, '\t'
        Backspace = 8,            // 0x08, '\b'

        // Keypad
        KP0 = 1073741922, // 0x40000062
        KP1 = 1073741913, // 0x40000059
        KP2 = 1073741914, // 0x4000005A
        KP3 = 1073741915, // 0x4000005B
        KP4 = 1073741916, // 0x4000005C
        KP5 = 1073741917, // 0x4000005D
        KP6 = 1073741918, // 0x4000005E
        KP7 = 1073741919, // 0x4000005F
        KP8 = 1073741920, // 0x40000060
        KP9 = 1073741921, // 0x40000061
        KPDecimal = 1073741923, // 0x40000063, SDLK_KP_PERIOD
        KPDivide = 1073741908, // 0x40000054
        KPMultiply = 1073741909, // 0x40000055
        KPSubtract = 1073741910, // 0x40000056
        KPAdd = 1073741911, // 0x40000057
        KPEnter = 1073741912, // 0x40000058
        KPEqual = 1073741927, // 0x40000067

        // Modifier keys continued
        LeftShift = 1073742049, // 0x400000E1
        LeftControl = 1073742048, // 0x400000E0
        LeftAlt = 1073742050, // 0x400000E2
        LeftSuper = 1073742051, // 0x400000E3, Left GUI (Windows/Command key)
        RightShift = 1073742053, // 0x400000E5
        RightControl = 1073742052, // 0x400000E4
        RightAlt = 1073742054, // 0x400000E6
        RightSuper = 1073742055, // 0x400000E7, Right GUI (Windows/Command key)
        Menu = 1073741942, // 0x40000076, SDLK_MENU

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
        
		//From SDL_mouse.h

        ButtonLeft = 1, // SDL_BUTTON_LEFT
        ButtonMiddle = 2, // SDL_BUTTON_MIDDLE
        ButtonRight = 3, // SDL_BUTTON_RIGHT
        ButtonX1 = 4, // SDL_BUTTON_X1 (often 'Back' button)
        ButtonX2 = 5, // SDL_BUTTON_X2 (often 'Forward' button)
        // Additional buttons (if any)
        Button6 = 6,
        Button7 = 7,
        Button8 = 8,
        ButtonLast = Button8,

        // For backward compatibility or convenience, map Button0-Button4
        Button0 = ButtonLeft,    // Button0 maps to Left Button (1)
        Button1 = ButtonRight,   // Button1 maps to Right Button (3)
        Button2 = ButtonMiddle,  // Button2 maps to Middle Button (2)
        Button3 = ButtonX1,      // Button3 maps to X1 Button (4)
        Button4 = ButtonX2,      // Button4 maps to X2 Button (5)
    } Button;

    inline std::ostream& operator<<(std::ostream& os, MouseButton button)
    {
        os << static_cast<int32_t>(button);
        return os;
    }
}