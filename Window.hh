#ifndef GUARD_Window_hh
#define GUARD_Window_hh

#include <ncurses.h>
#include <panel.h>
#include <string>

class Window {
public:
    Window(int sizeY, int sizeX, int posY, int posX) : window_(newwin(sizeY, sizeX, posY, posX)),
                                                       panel_(new_panel(window_)) {
        //window_ = newwin(sizeY, sizeX, posY, posX);
        //panel_ = new_panel(window_);
    }
    ~Window() {
        del_panel(panel_);
        delwin(window_);
    }
    Window(const Window&) = default;
    Window& operator=(const Window&) = default;

    Window(Window&) = default;
    Window& operator=(Window&) = default;

    int maxY() { return getmaxy(window_) - 1; }
    int maxX() { return getmaxx(window_) - 1; }

    void print(int y, int x, std::string s) { mvwprintw(window_, y, x, s.c_str()); }
    void print(int y, int x, char c) { mvwaddch(window_, y, x, c); }


private:
    WINDOW* window_;
    PANEL* panel_;
};

#endif
