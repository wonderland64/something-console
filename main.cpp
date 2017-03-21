// Main File of Some Project

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "Random.hh"
#include "GameController.hh"
//#include "Level.hh"

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    int prevY, prevX;
    getmaxyx(stdscr, prevY, prevX);
    //resizeterm(25, 50);

    int input;
    // int x = 0, y = 0;
    // int rowMax, colMax;
    //int rowMin, colMin;
    //getmaxyx(stdscr, rowMax, colMax);
    //mvaddch(1, 1, '@');
    //box(stdscr, 0, 0);
    //--colMax; --rowMax;
    //colMin = x = 1;
    //rowMin = y = 1;

    // Randomize variables
    Random rand;
    GameController gc;

    while (true) {
        input = getch();
        gc.handleInput(input);

        refresh();
    }

    resizeterm(prevY, prevX);
    delwin(stdscr);
    endwin();

    return 0;
}
