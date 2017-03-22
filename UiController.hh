#ifndef GUARD_UiController_hh
#define GUARD_UiController_hh

#include <ncurses.h>
#include <panel.h>
#include <string>

class UiController {
public:
    UiController() { init(); }

private:
    WINDOW* level;
    WINDOW* log;
    PANEL* levelPanel;
    PANEL* logPanel;

    void init() {
        level = newwin(getmaxy(stdscr)-20, getmaxx(stdscr)-1, 0, 0);
        log = newwin(20, getmaxx(stdscr)-1, getmaxy(stdscr)-20, 0);
        levelPanel = new_panel(level);
        logPanel = new_panel(log);



        for (int i = 0; i != getmaxy(log)+1; ++i) {
            const char* c = std::to_string(i+1).c_str();
            mvwprintw(log, i, i, c);
        }
        //hide_panel(logPanel);
        mvwprintw(level, getmaxy(level)-1, 1, "end of level");
        update_panels();
        doupdate();

    }

};

#endif
