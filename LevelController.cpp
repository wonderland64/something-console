#include "LevelController.hh"
#include "ncurses.h"
#include "Player.hh"

//Tile::redrawTileFunction Tile::redrawTile = &LevelController::redrawTile;

LevelController::LevelController() : currentLevel_(0), levels_() {}

void LevelController::generateLevel(Player& player, unsigned int roomAmount, unsigned int rowMax, unsigned int colMax) {
    // TODO: this should probably not use ncurses
    Level level(getmaxy(stdscr), getmaxx(stdscr));
    levels_.push_back(level);
    currentLevel_ = &levels_.back();
    currentLevel_->generateLevel(roomAmount, rowMax, colMax);
    spawnPlayer(player);
}

void LevelController::drawLevel() {
    currentLevel_->printLevelArray();
}

void LevelController::spawnPlayer(Player& player) {
    //Tile* tile = currentLevel_->randomTile();
    currentLevel_->spawnActor(player);
}

void LevelController::redrawTile(unsigned int y, unsigned int x, char graphic) {
    mvaddch(y, x, graphic);
}
