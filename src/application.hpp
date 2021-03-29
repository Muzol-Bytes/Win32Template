#ifndef _APPLICATION_HPP_
#define _APPLICATION_HPP_

#include "window/window.hpp"

class Application
{
public:
    Application();

    void run();

    void update();

    void handleInput(const MSG& msg);

private:
    Window window;
};

#endif // _APPLICATION_HPP_
