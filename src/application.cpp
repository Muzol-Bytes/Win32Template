#include "application.hpp"

#include "log/log.hpp"

const static uint16_t SCREEN_WIDTH  = 1080;
const static uint16_t SCREEN_HEIGHT = 720;

Application::Application()
    : window()
{
    if (!window.create("Win32", WS_OVERLAPPEDWINDOW, 0, SCREEN_WIDTH, SCREEN_HEIGHT))
        errorExit("Create Window: ");
}

void Application::run()
{
    window.show();

    MSG msg = { 0 }; 
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);

        handleInput(msg);
        update();

        DispatchMessage(&msg);
    }
}

void Application::update()
{
}

void Application::handleInput(const MSG& msg)
{
    /// NOTE: lParam and wParam are inside the msg struct
    switch (msg.message)
    {
        case WM_CHAR:
        {
            switch(msg.wParam)
            {
                case 0x1B: // Close window if `ESC` is pressed
                    window.destroy();
                    break;
            }
        }
        break;
    }
}
