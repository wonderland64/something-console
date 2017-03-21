#include "GameController.hh"

GameController::GameController() {}

void GameController::handleInput(int input) {
    inputController_.getInput(*this, input);
    advanceTurn();
}
void GameController::generateLevel(unsigned int roomAmount, unsigned int maxRow, unsigned int maxCol) {
    levelController_.generateLevel(player_, roomAmount, maxRow, maxCol);
    levelController_.drawLevel();
}
void GameController::movePlayer(int y, int x) {
    player_.move(y, x);
    //levelController_.drawLevel();
}
void GameController::advanceTurn() {
    while (player_.progressAction()) {
        // this should loop until the player action is finished
        // or something breaks the action. Which shouldn't happen here.
        // call other actors. probably other stuff.
    }
}
