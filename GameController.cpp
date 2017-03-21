#include "GameController.hh"

GameController::GameController() {}

void GameController::handleInput(int input) {
    inputController_.getInput(*this, input);
}
void GameController::generateLevel(unsigned int roomAmount, unsigned int maxRow, unsigned int maxCol) {
    levelController_.generateLevel(player_, roomAmount, maxRow, maxCol);
    levelController_.drawLevel();
}
void GameController::movePlayer(int y, int x) {
    player_.move(y, x);
    //levelController_.drawLevel();
}
