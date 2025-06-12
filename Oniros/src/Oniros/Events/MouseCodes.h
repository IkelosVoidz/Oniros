#include <SDL3/SDL_mouse.h>
#include <cstdint>

namespace Oniros {
    using MouseCode = uint16_t;

    namespace Mouse {
        enum : MouseCode {
            Button0 = SDL_BUTTON_LEFT,     
            Button1 = SDL_BUTTON_RIGHT,
            Button2 = SDL_BUTTON_MIDDLE,
            Button3 = SDL_BUTTON_X1,        // SDL uses X1 and X2 for what are often 'Back' and 'Forward' buttons.
            Button4 = SDL_BUTTON_X2,
            Button5 = 5,                    // These numbers map directly to SDL's extended button definitions.
            Button6 = 6,                    // Note: SDL supports more buttons, but they are not defined by default with specific SDL_BUTTON_* macros.
            Button7 = 7,                    // You can assign these based on your application needs.
            ButtonLast = Button7,
            ButtonLeft = Button0,
            ButtonRight = Button1,
            ButtonMiddle = Button2
        };
    }
}
