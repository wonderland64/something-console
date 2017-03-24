#include "GameController.hh"
#include <ncurses.h>

// TODO: change this. Maybe init()
GameController::GameController(int maxY, int maxX) {}

void GameController::handleInput(int input) {
    inputController_.getInput(*this, input);
    advanceTurn();
}
void GameController::generateLevel(unsigned int roomAmount, unsigned int maxRow, unsigned int maxCol) {
    levelController_.generateLevel(player_, 50, 50, roomAmount, maxRow, maxCol);
    levelController_.drawLevel();
}
void GameController::movePlayer(int y, int x) {
    player_.move(y, x);
    //levelController_.drawLevel();
}
void GameController::advanceTurn() {
    if (player_.validAction()) {
        while (player_.progressAction()) {
            // this should loop until the player action is finished
            // or something breaks the action. Which shouldn't happen here.
            // call other actors. probably other stuff.
        }
        update_panels();
        doupdate();
    }
}
