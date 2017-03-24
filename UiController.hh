#ifndef GUARD_UiController_hh
#define GUARD_UiController_hh

#include "Window.hh"
#include <ncurses.h>

// rename windowManager?
class UiController {
public:
    UiController();


    // It should take something that denotes what to build.
    // Might not work if they need pointers to windows from here.
    // Maybe friendship.
    static windowManipulator buildManipulator(...);
    // static printer buildPrinter();
    // static writer buildWriter();

private:
    Window log_;
};

#endif
