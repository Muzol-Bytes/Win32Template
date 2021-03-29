# Win32 api gui template
This is a simple template to get you setup to start developing with the win32 api.
It sets a window and easy manipulation through the `Application.cpp` file.

## Example: Printout key input
Inside `Application.cpp`
```c++
void Application::handleInput(const MSG& msg)
{
    switch (msg.message)
    {
        case WM_CHAR:
        {
            /// Printout key input
            std::wcout << "You pressed = " << (wchar_t) msg.wParam << '\n';

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
```

## Compile and run
Inside the root directory
```
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
$ ..\bin\Debug\Win32.exe
```
