// Main File of Some Project

#include <ncurses.h>
#include "GameController.hh"

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);

    // Keep terminal size, change back at program termination.
    int prevY, prevX;
    getmaxyx(stdscr, prevY, prevX);
    //resizeterm(25, 50);

    int input;
    GameController gc;

    while (true) {
        input = getch();
        gc.handleInput(input);

        // TODO: move refresh into RenderController or similar. Only call when something changed.
        refresh();
    }

    resizeterm(prevY, prevX);
    delwin(stdscr);
    endwin();

    return 0;
}
